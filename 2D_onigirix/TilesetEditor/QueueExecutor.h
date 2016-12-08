#pragma once
#include "boost/functional/hash.hpp"
#include "boost/lockfree/queue.hpp"
#include<thread>
// be aware of destruction !!!

namespace ONIGIRIX_GUI {
	//transform a function in a void retruning function 
	template<typename fct_pointer, typename... Params> void void_fct(Params... parameters) {
		fct_pointer(parameters);
	}

	template<class queueINFO> class QueueExecutor {
		/*
		THE CLASS TAKES POINTER AND THEN DELETE THE INFO AFTER USE !
		THE CLASS RETURN POINTER YOU HAVE TO DELETE THE INFO AFTER USAGE !
		*/
	public:

		QueueExecutor(void(*function)(queueINFO*)) :_loadFCT(function) {
			_busy = new std::atomic<short int>(false);
			_queue = new boost::lockfree::queue<queueINFO*>(0);
		}
		~QueueExecutor() {
			short int a = 1;
			if (!_busy->compare_exchange_strong(a, (short int)3)) {
				delete _busy;
			}
		}

		bool is_busy();

		void add_task(queueINFO*);//add a task 
		queueINFO* remove();// remove one task nullptr if no task to remove 

	private:

		void(*_loadFCT)(queueINFO*);

		std::atomic<short int>* _busy; //0 ->false not busy | 1-> bussy | 2-> the thread must delete the queue and over content 

		boost::lockfree::queue<queueINFO*>* _queue;

		void StartLoader();//startes the thread 
	};
	template<class queueINFO> void QueueExecutorWorker(std::atomic<short int>* _busy, boost::lockfree::queue<queueINFO*>* _queue, void(*fct)(queueINFO*)) {
		//this funtion is the function executed in the thread which work to empty the queu and execute it 
		queueINFO* treat;
		while (_queue->pop(treat)) {
			fct(treat);
			delete treat;
			if (_busy->load() == 3) {
				break;
			}
		}
		short int a=1;
		if (!_busy->compare_exchange_strong(a, 0)) {
			delete _busy;
			while (_queue->pop(treat)) delete treat;//empty the remaining el in the queu;
			delete _queue;
		}
		else {
			if (!_queue->empty() && _busy == 0) {
				QueueExecutorWorker(_busy, _queue, fct);
			}
		}
	}
	template<class queueINFO> void QueueExecutor<queueINFO>::StartLoader() {
		std::thread t(QueueExecutorWorker<queueINFO>, _busy, _queue, _loadFCT);
		t.detach();
	}
	template<class queueINFO> void QueueExecutor<queueINFO>::add_task(queueINFO* newTask) {
		short int a = 0;
		if (_busy->compare_exchange_strong(a, 1)) {
			_queue->push(newTask);
			StartLoader();
			return ;
		}
		_queue->push(newTask);
	}
	template<class queueINFO> bool QueueExecutor<queueINFO>::is_busy() {
		return _busy->load();
	}
	template<class queueINFO> queueINFO* QueueExecutor<queueINFO>::remove() {
		return _queue->pop();
	}
}
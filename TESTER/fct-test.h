
struct Hello
{
	int helloworld(Hello) { return 0; }
};

int helloworld(Hello) { return 0; }

struct Generic {};

//sfinae
Hello  operator+ (Hello, Hello) {
	return Hello();
}
void jeux(Hello) {

}

template <typename T, typename... Args>
class has_OPp
{
	template <typename C,
		typename = decltype(::jeux(std::declval<Args>()...))>
		static std::true_type test(int);
	template <typename C>
	static std::false_type test(...);

public:
	static constexpr bool value = decltype(test<T>(0))::value;
};

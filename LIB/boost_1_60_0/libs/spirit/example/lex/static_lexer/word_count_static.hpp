// Copyright (c) 2008-2009 Ben Hanson
// Copyright (c) 2008-2010 Hartmut Kaiser
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file licence_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Auto-generated by boost::lexer, do not edit

#if !defined(BOOST_SPIRIT_LEXER_NEXT_TOKEN_WC_NOV_10_2009_17_20_04)
#define BOOST_SPIRIT_LEXER_NEXT_TOKEN_WC_NOV_10_2009_17_20_04

#include <boost/detail/iterator.hpp>
#include <boost/spirit/home/support/detail/lexer/char_traits.hpp>

////////////////////////////////////////////////////////////////////////////////
// the generated table of state names and the tokenizer have to be
// defined in the boost::spirit::lex::lexertl::static_ namespace
namespace boost { namespace spirit { namespace lex { namespace lexertl { namespace static_ {

////////////////////////////////////////////////////////////////////////////////
// this table defines the names of the lexer states
char const* const lexer_state_names_wc[1] = 
{
    "INITIAL"
};

////////////////////////////////////////////////////////////////////////////////
// this variable defines the number of lexer states
std::size_t const lexer_state_count_wc = 1;

////////////////////////////////////////////////////////////////////////////////
// this function returns the next matched token
template<typename Iterator>
std::size_t next_token_wc (std::size_t& /*start_state_*/, bool& /*bol_*/, 
    Iterator &start_token_, Iterator const& end_, std::size_t& unique_id_)
{
    enum {end_state_index, id_index, unique_id_index, state_index, bol_index,
        eol_index, dead_state_index, dfa_offset};

    static const std::size_t npos = static_cast<std::size_t>(~0);
    static const std::size_t lookup_[256] = {
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 9, 7, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        9, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8 };
    static const std::size_t dfa_alphabet_ = 10;
    static const std::size_t dfa_[50] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 3, 2, 4, 1, 65536, 0, 0,
        0, 0, 0, 0, 2, 0, 1, 10,
        1, 0, 0, 0, 0, 0, 0, 0,
        1, 65537, 2, 0, 0, 0, 0, 0,
        0, 0 };

    if (start_token_ == end_)
    {
        unique_id_ = npos;
        return 0;
    }

    std::size_t const* ptr_ = dfa_ + dfa_alphabet_;
    Iterator curr_ = start_token_;
    bool end_state_ = *ptr_ != 0;
    std::size_t id_ = *(ptr_ + id_index);
    std::size_t uid_ = *(ptr_ + unique_id_index);
    Iterator end_token_ = start_token_;

    while (curr_ != end_)
    {
        std::size_t const state_ =
            ptr_[lookup_[static_cast<unsigned char>(*curr_++)]];

        if (state_ == 0) break;

        ptr_ = &dfa_[state_ * dfa_alphabet_];

        if (*ptr_)
        {
            end_state_ = true;
            id_ = *(ptr_ + id_index);
            uid_ = *(ptr_ + unique_id_index);
            end_token_ = curr_;
        }
    }

    if (end_state_)
    {
        // return longest match
        start_token_ = end_token_;
    }
    else
    {
        id_ = npos;
        uid_ = npos;
    }

    unique_id_ = uid_;
    return id_;
}

////////////////////////////////////////////////////////////////////////////////
// this defines a generic accessors for the information above
struct lexer_wc
{
    // version number and feature-set of compatible static lexer engine
    enum
    {
        static_version = 65536,
        supports_bol = false,
        supports_eol = false
    };

    // return the number of lexer states
    static std::size_t state_count()
    {
        return lexer_state_count_wc; 
    }

    // return the name of the lexer state as given by 'idx'
    static char const* state_name(std::size_t idx)
    {
        return lexer_state_names_wc[idx]; 
    }

    // return the next matched token
    template<typename Iterator>
    static std::size_t next(std::size_t &start_state_, bool& bol_
      , Iterator &start_token_, Iterator const& end_, std::size_t& unique_id_)
    {
        return next_token_wc(start_state_, bol_, start_token_, end_, unique_id_);
    }
};

}}}}}  // namespace boost::spirit::lex::lexertl::static_

#endif

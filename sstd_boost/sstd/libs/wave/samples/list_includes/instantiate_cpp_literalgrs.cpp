﻿/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    Sample: List include dependencies of a given source file

    http://www.boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/

#include "list_includes.hpp"            // config data

#if BOOST_WAVE_SEPARATE_GRAMMAR_INSTANTIATION != 0

#include <string>

#include <sstd/boost/wave/token_ids.hpp>

#include <sstd/boost/wave/token_ids.hpp>
#include <sstd/boost/wave/cpplexer/cpp_lex_token.hpp>

#include <sstd/boost/wave/grammars/cpp_literal_grammar_gen.hpp>
#include <sstd/boost/wave/grammars/cpp_intlit_grammar.hpp>
#include <sstd/boost/wave/grammars/cpp_chlit_grammar.hpp>

///////////////////////////////////////////////////////////////////////////////
//
//  Explicit instantiation of the intlit_grammar_gen, chlit_grammar_gen and
//  floatlit_grammar_gen templates with the correct token type. This
//  instantiates the corresponding parse function, which in turn instantiates
//  the corresponding parser object.
//
///////////////////////////////////////////////////////////////////////////////

typedef boost::wave::cpplexer::lex_token<> token_type;

template struct boost::wave::grammars::intlit_grammar_gen<token_type>;
#if BOOST_WAVE_WCHAR_T_SIGNEDNESS == BOOST_WAVE_WCHAR_T_AUTOSELECT || \
    BOOST_WAVE_WCHAR_T_SIGNEDNESS == BOOST_WAVE_WCHAR_T_FORCE_SIGNED
template struct boost::wave::grammars::chlit_grammar_gen<int, token_type>;
#endif
template struct boost::wave::grammars::chlit_grammar_gen<unsigned int, token_type>;

#endif // #if BOOST_WAVE_SEPARATE_GRAMMAR_INSTANTIATION != 0



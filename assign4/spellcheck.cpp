#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */

  //STEP1:
  auto space_iters= find_all ( source.begin(), source.end(), isspace );

  //STEP2:
  Corpus tokens;

  std::transform(
                 space_iters.begin(), //InputIt1 first1

                 space_iters.end()-1, //InputIt1 last1
                 
                 space_iters.begin()+1,//InputIt2 first2

                 std::inserter(tokens, tokens.end()),

                 [source] (std::string::const_iterator it1, std::string::const_iterator it2){

                  return Token{ source, it1, it2 };

                 }

                );

  
  //STEP3:
 std::erase_if( tokens, 
        [](auto token){
          
          if (token.content.empty()){
            return true;
          }

          else{
            return false;
          }

        }

      );

  return Corpus(tokens);

}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    namespace rv = std::ranges::views;

 
    auto misspelled = rv::filter(source, [&dictionary](const auto& token) {
        return !dictionary.contains(token.content);
    });

    auto with_suggestions = rv::transform(misspelled, [&dictionary](const auto& token) {
       
        auto suggestions_view = rv::filter(dictionary, [&token](const auto& word) {
            return levenshtein(token.content, word) == 1;
        });
        
        std::set<std::string> suggestions(suggestions_view.begin(), 
                                         suggestions_view.end());
        return Mispelling{token, suggestions};
    });

    // 3
    auto final_view = rv::filter(with_suggestions, [](const auto& m) {
        return !m.suggestions.empty();
    });

    return std::set<Mispelling>(final_view.begin(), final_view.end());
}

/* Helper methods */

#include "utils.cpp"
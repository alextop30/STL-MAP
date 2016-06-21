#include"defs.h"


int main(void)
{
     map<string,int>word_clean;								//initialize a map of string key and int value

     get_words(word_clean);								//get words call functionn to obtain the words
											//from the input stream

     print_words(word_clean);								//Print all of the clean words which are in the map

     return 0;										//return 0 out of the function
}


/*
* Function obtains words from a file using cin
* calls the function clean entry to clean each
* word, tests if the word is empty and inputs
* the word in the map and increments the value
*
* The function does not return a value but
* modifies the map which is passed by ref.
*/
void get_words ( M& word_clean)
{
     string word;									//storage variable for inputted word
     string clean;									//storage varibale for clean word

     while (cin >> word)								//while there is input
     {
        clean_entry(word, clean);							//call function clean entry

        if(clean.length() == 0)								//if cleaned word is empty
	{
             clean.clear();								//ignore the clean word
        }
        else
        {
             word_clean[clean]++;							//else add word to map and incrment
        }										//value
     }




}

/*
* Function clean entry responcible for looking at each
* word gathered for input stream and cleaning all
* punctuation characters so only words remain
*
* Function does not return a value but it does modify
* the clean word which is passed by reference
*
*/
void clean_entry(const string& s1, string &s_clean)
{
     typedef string:: iterator sii;							//define a type for string iterator
     s_clean = s1;									//set the the clean word equal to the
											//word gathered from input

     unsigned int i = 0;								//counter for while statement
     while (i < s1.length())								//while i is smaller than the length
     {											//of the word being examined
											//examine each character 

          sii first =s_clean.begin();							//initialize begnning iterator
          sii end = s_clean.end();							//initialize end iterator
          sii check;									//check itarator to hold value of find if
											//statement which will test if the character
											//is puctuation or not

          check = find_if(first, end, is_not_alnum);					//check if the character is punctuation
          if (check == first)
               s_clean.erase(check);							//if the first character is punctuation
	  else										//delete just the first character
          {
              int f = (check - first);							//elese calculate the distance between the
											//found character in the middle of the word
											//and the first iterator
              s_clean.erase(f);								//and delete the rest of the characters in the word
          }

          sii begin = s_clean.begin();							//initialize begnning iterator
          begin = (begin +i);								//increment the beginning iterator by one each time

          sii to_low = begin;								//call function to lower to turn upper case
											//characters to lower case
          int low =(tolower(*to_low));
          *to_low = static_cast<char>(low);						//type cast the integer returned from to low to
											//character to be which will be changed in clean word

          i++;										//increment the counter for while loop to look at second
											//character
     }


}

/*
* Function Print Words which is responcible for printing
* each clean word and the number of times it appears in the
* input stream after it has been cleaned along with stats
* of how many words were gathered and how many unique were
* inputted into the map.
*
* Functionn does not return anything but outputs the above
* described iformation to the console
*
*/

void print_words(const M& word_clean)
{
      int number_per_line;								//storage var modulus division test for items per line
      int count = 0;									//count for number of items on a line
      int count_second = 0;								//count for the total words read in


      for(auto j = word_clean.begin(); j != word_clean.end(); ++j)			//step through the map printing each pair with the
      {
            cout << setw(ITEM_W) << left << j ->first					//assign attributes
	    <<" : "  << setw(3) << j-> second <<"  ";

            count_second = count_second + j -> second;					//increment the total count by the value in each pair

            number_per_line = (count+1) % NO_ITEMS;					//check if the numbers printed are completely divisible
											//so that output is alligned per the requirements
            if(number_per_line == 0)							//if completely divisible
                 cout << endl;								//shift cursor to the next line

            count ++;									//incrment the line counter

      }

      unsigned int words_clean_out = word_clean.size();					//total unique words setting it equal to the size of the map

      cout << endl;									//print blank linne for output clarity

      cout << "no of words in the input stream  : "					//print stats for total words read from input stream
      << count_second <<endl;
      cout << "no of words in the output stream : "					//total unique words inputted into map container
      << words_clean_out << endl;

}

/*
* Function is not alfanumeric - is responcible for returningn
* a boolien value if the character tested is punctuation mark
* it is used as unari predicate for the find if statement in
* the clean words functionn
*
* Function returns true if character is punction and false
* otherwise. Does not output anything to the console
*/

bool is_not_alnum(const char& c)
{
      return ispunct(c);								//return a true if a punctuation is encountered
}

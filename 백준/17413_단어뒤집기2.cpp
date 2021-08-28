#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string result="";
	string word = "";
	int startword=0;
	getline(cin,s);
	for (int i = 0; i < s.size(); i++) {
		//태그먼저 인지해서 태그 걸리면 그냥 result에 넣도록
		if (i==0 && s[i] == '<') {
			while (i < s.size()) {
				if (s[i] == '>') {
					result += '>';
					startword = i + 1;
					break;
				}
				result += s[i];
				i++;
			}
			
		}
		else if (i!=0 && s[i] == '<') {//<전의 문자.
			word = "";
			word = s.substr(startword, i - startword);
			startword = i + 1;
			for (int subi = word.size() - 1; subi >= 0; subi--) {
				result += word[subi];
			}
			while (i < s.size()) {
				if (s[i] == '>') {
					result += '>';
					startword = i + 1;
					break;
				}
				result += s[i];
				i++;
			}
		}
		else if (s[i] == ' ') {//끝이 아닌 공백
			word = "";
			word = s.substr(startword, i - startword);
			startword = i+1;
			for (int subi = word.size()-1; subi >= 0; subi--) {
				result += word[subi];
			}
			result += ' ';
		}
		else if (i + 1 == s.size()) {//끝
			word = "";
			word = s.substr(startword, i - startword + 1);
			startword = i + 1;
			for (int subi = word.size() - 1; subi >= 0; subi--) {
				result += word[subi];
			}
		}
	}
	cout << result;
	return 0;
}

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <set>
using namespace std;

bool isContentWord(string s, string word) {
	if(s.length() < word.length()) return false;
	string temp;
	for(long i = 0; i <= s.length() - word.length(); i++) {
		temp = s.substr(i, word.length());
		if(word.compare(temp) == 0) {
			if(i >= 1 && i <= (s.length() - word.length() - 1)) {
				if(s[i - 1] == ' ' && s[i + word.length()] == ' ') return true;
			} else if(i == 0) {
				if(s[i + word.length()] == ' ' || s[i + word.length()] == '\0') return true;
			} else if(i == (s.length() - word.length())) {
				if(s[s.length() - word.length() - 1] == ' ' || s[s.length() - word.length() - 1] == '\0') return true;
			}
		}
	}
	return false;
}

bool isSpam(set<string> strSet, string message) {
	set<string>::iterator it;
	ifstream ifs;
	string buf;
	long numSpamMail = 0, numValidMail = 0;
	//
	ifs.open("spamList.txt");
	if(ifs.is_open()) {
		while(!ifs.eof()) {
			getline(ifs, buf);
			numSpamMail++;
		};
	} else cout << "khong mo dc file!";
	ifs.close();
	//
	ifs.open("validList.txt");
	if(ifs.is_open()) {
		while(!ifs.eof()) {
			getline(ifs, buf);
			numValidMail++;
		};
	} else cout << "khong mo dc file!";
	ifs.close();
	//
	float pSpam;
	float pValid;
	string word;
	long position;
	long numWord;
	//
	pSpam = (float)(numSpamMail + 1) / (numSpamMail + numValidMail + 1);
	for (it=strSet.begin(); it != strSet.end(); ++it) {
		word = *it;
    	numWord = 0;
		ifs.open("spamList.txt");
		if(ifs.is_open()) {
			while(!ifs.eof()) {
				getline(ifs, buf);
				if(isContentWord(buf, word)) numWord++;
			};
		} else cout << "khong mo dc file!";
		ifs.close();
		pSpam *= ((float)(numWord + 1) / (numSpamMail + 1));
	}
	//
	pValid = (float)(numValidMail + 1) / (numSpamMail + numValidMail + 1);
	for (it=strSet.begin(); it != strSet.end(); ++it) {
		word = *it;
    	numWord = 0;
		ifs.open("validList.txt");
		if(ifs.is_open()) {
			while(!ifs.eof()) {
				getline(ifs, buf);
				if(isContentWord(buf, word)) numWord++;
			};
		} else cout << "khong mo dc file!";
		ifs.close();
		pValid *= ((float)(numWord + 1) / (numValidMail + 1));
	}
	//
	cout <<"spam: " << pSpam << "\t valid: " << pValid << endl;
	ofstream ofs;
	if(pSpam > pValid) {
		ofs.open("spamList.txt", ios_base::app);
		if(ofs.is_open()) {
			// ofs << endl;
			// ofs << message;
		} else cout << "khong mo dc file!";
		ofs.close();
		return true;
	} else {
		ofs.open("validList.txt", ios_base::app);
		if(ofs.is_open()) {
			// ofs << endl;
			// ofs << message;
		} else cout << "khong mo dc file!";
		ofs.close();
		return false;
	}
}

int main() {
	set<string> strSet;
	string incomeMess;
	string buf;
	while(1) {
		strSet.clear();
		incomeMess = "";
		cout <<"Nhap message: ";
		getline(cin, incomeMess);
		stringstream ss(incomeMess);
		while(!ss.eof()) {
			getline(ss, buf, ' ');
			strSet.insert(buf);
		}
		if(isSpam(strSet, incomeMess)) cout << ">>> Thu rac!";
		else cout << ">>> Thu binh thuong!";
		cout << endl;
	}
	return 0;
}

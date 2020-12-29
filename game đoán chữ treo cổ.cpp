#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void result(int n) {

	switch(n){
        case 7:
    cout  << "   ________________" << endl
       << "   |              |" << endl
       << "   |              O" << endl
       << "   |             /|\\  " << endl
       << "   |            / | \\ " << endl
       << "   |             / \\ " << endl
       << "   |            /   \\ " << endl
       << "   |" << endl
       << "  ---" << endl;
            break;
        case 6:
            cout  << "   ________________" << endl
            << "   |              |" << endl
            << "   |              O" << endl
            << "   |             /|\\  " << endl
            << "   |            / | \\ " << endl
            << "   |             /  " << endl
            << "   |            /    " << endl
            << "   |" << endl
            << "  ---" << endl;
            break;
        case 5:
            cout  << "   ________________" << endl
            << "   |              |" << endl
            << "   |              O" << endl
            << "   |             /|\\  " << endl
            << "   |            / | \\ " << endl
            << "   |             " << endl
            << "   |             " << endl
            << "   |" << endl
            << "  ---" << endl;
            break;
        case 4:
            cout  << "   ________________" << endl
            << "   |              |" << endl
            << "   |              O" << endl
            << "   |             /| " << endl
            << "   |            / | " << endl
            << "   |          " << endl
            << "   |           " << endl
            << "   |" << endl
            << "  ---" << endl;
            break;
        case 3:
            cout  << "   ________________" << endl
            << "   |              |" << endl
            << "   |              O" << endl
            << "   |              |  " << endl
            << "   |              |  " << endl
            << "   |            " << endl
            << "   |            " << endl
            << "   |" << endl
            << "  ---" << endl;
            break;
        case 2:
            cout  << "   ________________" << endl
            << "   |              |" << endl
            << "   |              O" << endl
            << "   |            " << endl
            << "   |         " << endl
            << "   |           " << endl
            << "   |            " << endl
            << "   |" << endl
            << "  ---" << endl;
            break;
        case 1:
            cout  << "   ________________" << endl
            << "   |              |" << endl
            << "   |           " << endl
            << "   |               " << endl
            << "   |             " << endl
            << "   |              " << endl
            << "   |           " << endl
            << "   |" << endl
            << "  ---" << endl;
            break;
        case 0:
            cout  << "   ________________" << endl
            << "   |              " << endl
            << "   |              " << endl
            << "   |              " << endl
            << "   |           " << endl
            << "   |            " << endl
            << "   |            " << endl
            << "   |" << endl
            << "  ---" << endl;
            break;
            
    }
}

int randid(int n) {
    srand(time(NULL));
	return rand()%n;
}

string word() {

	string library[]={"jackjack", "kicmkicm", "sontung", "edsheeran"};
	int n = randid(4);
	return library[n];
}

// HAM SET UP VA CHOI GAME
void startPlay() {
	string secret = word();
    vector<char> origin(secret.length());
	vector<char> hide(secret.length(), '-');
    for (int i=0; i<secret.length(); i++) {
		origin[i] = secret[i];
		cout<<hide[i];
	}
	cout<<endl;

	int time, checkGuess;
	char guess;
	bool check=false;

	time=0;
	while (check==false && time<7) {

		cout<<"Guess: ";
		cin>>guess;
		check=true;
		checkGuess=0;
		for (int i=0; i<secret.length(); i++) {
			if (guess==origin[i] && hide[i]=='-' && checkGuess==0) {
				hide[i]=origin[i];
				checkGuess++;
				check=false;
			}
			cout<<hide[i];
		}
		cout<<endl;
		if (check==false) {
			result(time);
		}
		 else {
			time++;
			result(time);
			cout<<"\n\n"<<endl;
		    check=false;
		}
		//Kiem tra xem đã đủ ô hết chưa
		int count=secret.length();
		for (int i=0; i<secret.length(); i++) {
            if (hide[i]=='-') {
				count=0;
				break;
			}
		}
		if (count==secret.length()) {
			check=true;
			break;
		}
		//__________________________
	}
	if (check==true) cout<<"You win"<<endl;
		 else cout<<"You can play the second time"<<endl;
	cout<<"\n\n\n"<<endl;

}

// HAM MAIN
int main() {
	con: cout<<"Are you ready?"<<endl<<"1 for Play\n0 for Delay\n-1 for Quit"<<endl;
	int x;
	cin>>x;
	if (x==0) goto con;
	if (x==1) {
		startPlay();
		goto con;
	}
	if (x==-1) cout<<"Have fun gamer ^^"<<endl;
	cout<<"\n\n\n"<<endl;
}
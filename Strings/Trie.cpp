#include <bits/stdc++.h>
 
using namespace std;
 
struct node{
	bool end;
	struct node* letters[3];
 
} *head; 
 
 
void init(){
	head = new node();
	head->end = false;
}
 
 
void add(string word){
	node* helper = head;
	
	for(int i = 0; i< word.size(); i++){
		int letter = word[i] - 'a';
		
		if(helper->letters[letter] == NULL)
			helper->letters[letter] = new node();
			
		helper = helper->letters[letter];
		
	}
	
	helper->end = true;
}
 
int walk(string word, int i, node* helper){
	
	for(int k = i; k < word.size(); k++){
		int letter = word[k] - 'a';
		
		if(k != (word.size() - 1) &&  helper->end){
			return 2;
		}
		
		if(helper->letters[letter] == NULL){
			
			
			if(k == word.size() - 1 ){
				if(helper->letters[(letter + 1)% 3] != NULL 
					&& helper->letters[(letter + 1)% 3]->end)
					return 1;
				
				else if(helper->letters[(letter + 2)% 3] != NULL 
					&& helper->letters[(letter + 2)% 3]->end)
					return 1;
						
				else
					return 2;
			}
			else if( helper->letters[(letter + 1) % 3] == NULL)
				return 1 + walk(word, k + 1, helper->letters[(letter + 2) % 3]) ;
			
			else if( helper->letters[(letter + 2) % 3] == NULL)
				return 1 + walk(word, k + 1, helper->letters[(letter + 1) % 3]) ;
			else {
				return 1 + min( walk(word, k + 1, helper->letters[(letter + 1) % 3]) ,
							walk(word, k + 1, helper->letters[(letter + 2) % 3]	));
			}
		}
		
		helper = helper->letters[letter];
	}
	if(helper->end)
		return 0;
	else
		return 2;	
}
 
int main(){
	init();
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;	
		add(s);
	}
	
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		int a = walk(s, 0, head);
		if( a == 1)cout << "YES" << endl ;
		else cout << "NO" << endl ;
	}	
}

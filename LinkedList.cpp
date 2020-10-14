// Dread it. Run from it. Destiny arrives all the same.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 4005;
const double PI = 3.1415926;

#define endl "\n"
#define vll vector<int>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define all(container) container.begin(), container.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define printArr(name,from,to) for(int x = from; x < to; x++) cout << name[x] << " ";
#define fi first
#define se second
#define mp make_pair
#define prime1 304933
#define prime2 15486277 
#define mod2 179424691
#define int ll

typedef struct Node
{
	int data;
	Node* next;
}Node;

Node* getNode()
{
	Node* temp = new Node;
	temp->data = 0;
	temp->next = NULL;
	return temp;
}

void append(Node* root, int data)
{
	Node* temp = getNode();
	temp->data = data;
	Node* iter = root;
	while(iter->next != NULL){
		iter = iter->next;
	}
	iter->next = temp;
	return;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		Node* root = getNode();
		int size = 0;
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			append(root, x);
			size++;
		}
		
		int find = n/2;
		int counter = -1;
		Node* temp = root;
		while(counter < find){
			temp = temp->next;
			counter++;
		}
		cout << temp->data << endl;
	}	
	return 0;
}

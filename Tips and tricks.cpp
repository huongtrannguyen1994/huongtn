max_element(a.begin(), a.end());

what's assert
whta's reverse

// ep kieu trong c++
float c = 35.8f;
int b = (int)c + 1;

pow(kiểu dữ liệu a, kiểu dữ liệu n), với a là cơ số và n là lũy thừa bậc n(số mũ).

// Priority Queue

- priority_queue ();

priority_queue<int,vector<int>, greater<int>> q; 
q.push(int); // sap xep theo tu tu tu nho den lon va top() cua q la phan tu nho nhat.

priority_queue<int> q; 
q.push(int); // sap xep theo tu tu tu lon den nho va top() cua q la phan tu lon nhat.

less và greater
priority_queue<int,vector<int>, less<int>> q; 
q.push(int); // sap xep theo tu tu tu lon den nho va top() cua q la phan tu lon nhat.

// tolower(char); X -> x
    toupper(char); // x -> X


vector<int> a = {1, 3, 6, 1, 3, 8, 2, 9};
vector<int>::iterator x = max_element(a.begin(), a.end());
cout << " " << *x; //9


cfg.resize(3, 0); // {0, 0, 0}

next_permutation(a.begin(), a.end()); // hoan vi cua tat ca cach so trong vector a.
ceil(int) // làm tròn số lên số nguyên

vector<int> a;
a.back() // lấy phần tử cuối cùng
a.front() // lấy phần tử đầu tiên
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

int a[] = {40, 30, 20, 20, 50, 40, 30, 20, 10};
    vector < int > v(a, a + 9);
	
    // a = {10, 10, 20, 20, 30, 30, 40, 40, 50}
    sort(a, a + 9);
	
    // Tìm vị trí của phần tử đầu tiên lớn hơn 30 trong mảng a.
    // Muốn đưa ra vị trí là số nguyên thì lấy kết quả hàm trừ đi iterator a[0].
    int pos1 = lower_bound(a, a + 9, 30) - a;
    cout << "Vị trí đầu tiên lớn hơn 30 là: " << pos1 << endl;

    // v = {50, 40, 40, 30, 30, 20, 20, 10, 10};
    sort(v.begin(), v.end(), comp);
    
    // Tìm vị trí đầu tiên nhỏ hơn hơn 50 trong đoạn [0, 5] của vector v.
    // Tương tự, lấy hai iterator trừ cho nhau để ra được vị trí là số nguyên.
    int pos2 = lower_bound(v.begin(), v.end(), 50) - v.begin();
    cout << "Vị trí đầu tiên nhỏ hơn 50 là: " << pos2;

set<pair<ull, ull>> tank; //Tập hợp này sẽ lưu trữ giá và dung tích các phần nhiên liệu có giá khác nhau mà tàu đang mang
		                          //Lưu ý thì set sẽ luôn sắp xếp theo thứ tự từ nhỏ đến lớn của phần tử first của pair
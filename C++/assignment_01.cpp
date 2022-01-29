#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

void print_vector(vector<string> a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> set_union(vector<int> a, vector<int> b) {
	vector<int> ans;

    int mp[10] = {0};
    int n = a.size(), m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
        int value = a[i];
		mp[value] += 1;
        ans.push_back(value);
    }

	for (int i = 0; i < m; i++) {
        int value = b[i];
        if( mp[value] == 0 )
		    ans.push_back(value);
    }

    sort(ans.begin(), ans.end());
	return ans;
}

vector<int> set_intersection(vector<int> a, vector<int> b) {
    vector<int> ans;
    int mp[10] = {0};
    int i = 0, j = 0;
    int n = a.size();
    int m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while (i < n && j < m) {
        if (a[i] > b[j])
            j++;

        else if (b[j] > a[i])
            i++;

        else {
            ans.push_back(a[i]);
            i++, j++;
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

vector<string> generate_power_set(vector<int> a) {
    vector<string> ans;
    int set_size = a.size();
    int pow_set_size = pow(2, set_size);

    for (int counter = 0; counter < pow_set_size; counter++) {
        string value = "";
        for (int j = 0; j < set_size; j++) {

            if (counter & (1 << j)) {
                value += to_string(a[j]) + " ";
            }
        }

        if (value != "")
            ans.push_back(value + ", ");
    }

    ans.push_back("φ");
    return ans;
}

vector<string> cross_product(vector<string> A, vector<string> B) {
    vector<string> C;

    for (int i = 0; i < A.size(); i++) {

        for (int j = 0; j < B.size(); j++) {

            string value = A[i] + " " + B[j];

            if (i != A.size()-1 || j != B.size()-1)
                value += ", ";

            C.push_back(value);
        }

    }

    return C;
}

void task1() {
    vector<int> A = {1, 3, 5, 2};
    vector<int> B = {1, 4, 6, 8, 5};
    vector<int> C = {1, 4, 6, 8};
    vector<int> D = {1, 2, 6, 10};

	vector<int> r1 = set_union(A, C);
    vector<int> r2 = set_union(A, D);
    vector<int> r3 = set_intersection(r1, r2);

    cout << "(AUC) Ո (AUD) : ";
    print_vector(r3);

    cout << "\ntask1\n\n";
}

void task2() {
	vector<int> A = {1, 3, 2};
	vector<string> ans = generate_power_set(A);
    print_vector(ans);
    cout << "\ntask2\n\n";
}

void task3() {
    vector<string> A = {"1", "3"};
    vector<string> B = {"a", "b", "f"};
    vector<string> C = cross_product(A, B);
    print_vector(C);
    cout << "\ntask3\n\n";
}

void task4() {
    vector<int> A = {1, 3, 5, 2};
    vector<int> B = {1, 4, 6, 8, 5};

    bool r1 = set_union(A, B) == set_union(B, A);
    bool r2 = set_intersection(A, B) == set_intersection(B, A);

    cout << "A U B = B U A : " << r1 << endl;
    cout << "A Ո B = B Ո A : " << r2 << endl;
    cout << "\ntask4\n\n";
}

void task5() {
    vector<int> A = {1, 3, 5, 2};
    vector<int> B = {1, 4, 6, 8, 5};
    vector<int> C = {1, 4, 6, 8};

    bool r1 = set_union(set_union(A, B), C) == set_union(A, set_union(B, C));
    bool r2 = set_intersection(set_intersection(A, B), C) == set_intersection(A, set_intersection(B, C));

    cout << "(A U B) U C = A U (B U C) : " << r1 << endl;
    cout << "(A Ո B) Ո C = A Ո (B Ո C) : " << r2 << endl;
    cout << "\ntask5\n\n";
}

void task6() {
    vector<int> A = {1, 3, 5, 2};
    vector<int> B = {1, 4, 6, 8, 5};
    vector<int> C = {1, 4, 6, 8};

    bool r1 = set_union(A, set_intersection(B, C)) == set_intersection(set_union(A, B), set_union(A, C));
    bool r2 = set_intersection(A, set_union(B, C)) == set_union(set_intersection(A, B), set_intersection(A, C));

    cout << "A U (B Ո C) = (A U B) Ո (A U C) : " << r1 << endl;
    cout << "A Ո (B U C) = (A Ո B) U (A Ո C) : " << r2 << endl;
    cout << "\ntask6\n\n";
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();

    return 0;
}

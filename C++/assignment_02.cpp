#include <bits/stdc++.h>
using namespace std;

int length(char s[]) {
    int i = 0;
    while (s[i]!='\0') {
        i++;
    }
    return i;
}

void print_string(char s[]) {
    for(int i = 0; i < length(s); i++)
        cout << s[i];
    cout << endl;
}

bool compare_string(char s[], char t[]) {

    if(length(s) == length(t)) {

        for(int i = 0; i < length(s); i++) {
            if(s[i] != t[i])
                return false;
        }
    }
    else
        return false;

    return true;
}

char* reverse_string(char s[]) {
    int n = length(s);
    char* t = new char[n];

    for(int i = 0, j = n-1; i < n; i++, j--)
        t[j] = s[i];

    return t;
}

char* merge_string(char fname[], char lname[]) {
    int p = length(fname);
    int q = length(lname);
    int n = p + q;

    char* full_name = new char[n];
    int i = 0, j = 0;

    for (i; i < p; i++)
        full_name[i] = fname[i];

    for (i, j; j < q; i++, j++)
        full_name[i] = lname[j];

    return full_name;
}

vector<int> calculate_position(char s[]) {
    int n = length(s);
    vector<int> z;
    z.resize(n);

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (z[i-l]+i <= r)
            z[i] = z[i-l];
        else {
            l = i;
            if (i > r)
                r = i;
            for (z[i] = r-i; r<n; ++r, ++z[i])
                if (s[r] != s[z[i]])
                    break;
            --r;
        }
    }

    return z;
}

void task1() {
    char s[] = "hello world";
    int i = length(s);
    cout << i << endl;
    cout << "\ntask1\n\n";
}

void task2() {
    char s[] = "hello world";
    char t = 'l';
    int cnt = 0;

    for (int i = 0; i < length(s); i++) {
        if(s[i] == t)
            cnt++;
    }

    cout << cnt << endl;
    cout << "\ntask2\n\n";
}

void task3() {
    char main_string[] = "world world hello world";
    char substring[] = "world";
    char* working_string = merge_string(substring, main_string);
    vector<int> z = calculate_position(working_string);

    int p = length(working_string);
    int q = length(substring);

    for (int i = q; i < p; i++)
        if (z[i] >= q)
            cout << i - q << endl;

    cout << "\ntask3\n\n";
}

void task4() {
    int ans = 0;
    char main_string[] = "hello world";
    char substring[] = "world";
    char* working_string = merge_string(substring, main_string);
    vector<int> z = calculate_position(working_string);

    for(int i = length(substring); i < length(working_string); i++) {
        if(z[i] >= length(substring)) {
            int v = i - length(substring);
            if(v == 1)
                ans += 1;
            else if(v == length(main_string)-length(substring))
                ans += 2;
        }
    }

    if(ans==1)
        cout << "prefix" << endl;
    else if (ans==2)
        cout << "suffix" << endl;
    else if (ans==3)
        cout << "prefix and suffix both" << endl;
    else
        cout << "nothing" << endl;

    cout << "\ntask4\n\n";
}

void task5() {
    char s[] = "hello";
    char t[] = "world";
    char* working_string = merge_string(s, t);
    print_string(working_string);
    cout << "\ntask5\n\n";
}

void task6() {
    char s[] = "hello world";
    char* t = reverse_string(s);
    print_string(t);
    cout << "\ntask6\n\n";
}

void task7() {
    char s[] = "hello ";
    char t[] = "world";
    bool ans = compare_string(s, t);

    if(ans==true)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
    cout << "\ntask7\n\n";
}

void task8() { // s = ut // (s)r and (t)r + (u)r
    char s[] = "DogCat";
    char t[] = "Dog";
    char u[] = "Cat";

    char* v1 = reverse_string(s);
    char* tr = reverse_string(t);
    char* ur = reverse_string(u);
    char* v2 = merge_string(ur, tr);

    bool ans = compare_string(v1, v2) ;
    cout << ans << endl;
    cout << "\ntask8\n\n";
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();

    return 0;
}
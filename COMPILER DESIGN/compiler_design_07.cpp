#include <bits/stdc++.h>

using namespace std;


stack <double> number;
stack <char> xfactor;


double operation() {
    double c;
	double b = number.top(); number.pop();
	double a = number.top(); number.pop();
	char op = xfactor.top(); xfactor.pop();
	
	switch(op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		case '%': return fmod(a, b);
		default: return 0;
	}
}


double generate(string expression) {
    map<char, int> preference;

    preference['+'] = 1;
    preference['-'] = 1;
    preference['*'] = 2;
    preference['/'] = 2;
    preference['%'] = 2;
	
	for(int i = 0; i < expression.length(); i++) {
		if(expression[i] == '(')
			xfactor.push(expression[i]);

		else if(isdigit(expression[i])) {
			int val = 0;

			while(i < expression.length() && isdigit(expression[i])) {
				val = (val*10) + (expression[i]-'0');
				i++;
			}
			
			number.push(val);
			i--;
		}

		else if(expression[i] == ')') {
			while(!xfactor.empty() && xfactor.top() != '(') {
				double ans = operation();
				number.push(ans);
			}
			
			if(!xfactor.empty())
			    xfactor.pop();
		}
		
		else {
			while(!xfactor.empty() && preference[xfactor.top()]	>= preference[expression[i]]) {
				double ans = operation();
				number.push(ans);
			}
			
			xfactor.push(expression[i]);
		}
	}

	while(!xfactor.empty()) {
		double ans = operation();
		number.push(ans);
	}

	return number.top();
}


int main()
{
    string expressions[4] = {"3+4-5", "2*4-8/2", "15*10%7-2", "(122+3)/15-5"};

    for (string x : expressions)
        cout << generate(x) << endl;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;



vector<string> split(string s) {
    vector<string> parts;
    stringstream ss(s);
    string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    return parts;
}


int totalRevenue(map<string, int>& revenue_from) {
    int sum = 0;
    for (auto entry : revenue_from) {
        sum += entry.second;  
    }
    return sum;
}

int main() {
    map<string, int> revenue_from; 
    map<pair<string, string>, int> consume_of_consumer;
    int count_orders = 0;  
    string line;

    while (getline(cin, line)) {
        if (line == "#") break;
        vector<string> lines = split(line);

        string cusID = lines[0];
        string proID = lines[1];
        int price = stoi(lines[2]);
        string shopID = lines[3];
        string time = lines[4];

        count_orders++;       
        revenue_from[shopID] += price;
        consume_of_consumer[{shopID, cusID}] += price;
        
    }

    while (getline(cin, line)) {
        if (line == "#") break;

        vector<string> lines = split(line);
        if (lines[0] == "?total_number_orders") {
            cout << count_orders << endl;  

        } else if (lines[0] == "?total_revenue") {
            int result = totalRevenue(revenue_from);  
            cout << result << endl;

        } else if (lines[0] == "?revenue_of_shop") {
            string shopID = lines[1];  
            cout << revenue_from[shopID] << endl;  

        } else if (lines[0] == "?total_consume_of_customer_shop") {
            string cusID = lines[1];
            string shopID = lines[2];
            cout<<consume_of_consumer[{shopID, cusID}]<<endl;

        } else if (lines[0] == "?total_revenue_in_period") {
              
              
        } 
    }
    return 0;
}

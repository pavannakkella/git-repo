#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;

class Widgets{

    public:
    template<typename T>
    void display(const T& myitr , string msg){
        cout<<msg<<endl;
        for(auto widget : myitr){
            cout<<widget<<endl;
        }

    }

    void combine(const vector<string>& itr1 , set<string>& itr2 , vector<string>& citr){
        copy(itr1.begin() , itr1.end() , back_inserter(citr));
        copy(itr2.begin() , itr2.end() , back_inserter(citr));

    }

    void find_widget(const set<string>& itr, string widget) {
        auto id = itr.find(widget);  // Correct usage of set::find
        if (id != itr.end()) {  // Check if the widget is found
            cout << *id << " widget found in the set." << endl;
        } else {
            cout << widget << " not found in the set." << endl;
        }
    }
 };


int main(){

    Widgets mywidget;
    vector<string> dynamic_widgets;
    set<string> static_widgets;
    vector<string> Combined_widgets;

    static_widgets.insert("Logo");
    static_widgets.insert("WarningLights");

    dynamic_widgets.push_back("Speedometer");
    dynamic_widgets.push_back("Tachometer");

    mywidget.display(static_widgets , "These are the static widgets :");
    mywidget.display(dynamic_widgets , "These are the dynamic widgets :");
    mywidget.combine(dynamic_widgets , static_widgets , Combined_widgets);
    mywidget.display(Combined_widgets , "These are the combined widgets :");
    mywidget.find_widget(static_widgets , "Tachometer");


    return 0;

}
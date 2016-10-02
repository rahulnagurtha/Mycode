#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
    // freopen("in.txt", "r", stdin);
    //declaration
    int number,temp,men_pair[100],women_pair[100],flag,it;
    vector<list<int> > m_order(100);
    vector<list<int> > w_order(100);
    bool w_status[100];
    deque<int> rem;

    //input
    for (int i = 0; i < 100; ++i) {
        w_status[i]=false;
    }
    printf("number of matchings: ");
    cin >> number ;
    for (int i = 0; i < number; ++i) {
        rem.push_back(i);
    }
    printf("men order: \n");
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < number; ++j) {
            cin >> temp ;
            m_order[i].push_back(temp);
        }
    }
    printf("women order: \n");
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < number; ++j) {
            cin >> temp ;
            w_order[i].push_back(temp);
        }
    }

    //GS algo

    //iterating over each man
    while(!rem.empty()) {
        it=rem.front();
        //looking at his preferences
        for (list<int>::iterator it1 = m_order[it].begin(); it1!= m_order[it].end(); ) {
            //if the current woman is not engaged,then engage her
            if(w_status[*it1]==false) {
                printf("m-%d engaged directly to w-%d\n",it,*it1);
                w_status[*it1]=true;
                women_pair[*it1]=it;
                men_pair[it]=*it1;
                m_order[it].pop_front();
                break;
            }
            else {
                flag=0;
                for (list<int>::iterator it2 = w_order[*it1].begin(); it2!= w_order[*it1].end(); ++it2) {
                    //if this man is more capable break the engagement and add the previous man back to list
                    if(it == *it2) {
                        printf("w-%d break up with m-%d and accepts m-%d\n",*it1,women_pair[*it1],it);
                        rem.push_back(women_pair[*it1]);
                        men_pair[it]=*it1;
                        women_pair[*it1]=it;
                        flag=1;
                        break;
                    }
                    //else reject his proposal
                    if(*it2 == women_pair[*it1]) {
                        m_order[it].pop_front();
                        // it1=m_order[it].begin()--;
                        printf("m-%d cudnt tempt w-%d\n",it,*it1);
                        break;
                    }
                }
                //engaged already
                if(flag==1) break;
                it1=m_order[it].begin();
            }
        }
        // printf("here\n");
        rem.pop_front();
    }
    printf("And now the celebrations begin,the matchings are : \n");
    for (int i = 0; i < number; ++i) {
        printf("%d,%d\n",i,men_pair[i]);
    }
    return 0;
}
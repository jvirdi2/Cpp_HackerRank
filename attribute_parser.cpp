#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/* This is a basic attribute parser. The code takes inputs like 
4 8
<tag1 value = "HelloWorld" okay = "what">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
tag2~name (*This is not a logical query. Should be instead tag1.tag2~name)
tag2~what
tag1~okay
tag5~value
tag1.tag5~name

Here N=4 and 8 is queries. 
Restrictions: 
1) For each entry in N, you have to use tag(i) as entry (not like <abc value= "a!">. abc is invalid)
2) You need to give a logical query as in for each query i, the tagi.tagp..... and so on needs to be consistent

My code gives tag2~name as "Name1". Actually on HackerRank this is not allowed. They dispay it as "Not Found!".
In order to get "Name1" displayed, you have to write tag1.tag2~name only
*/


int main(){
	int N=0;
	int Q=0;
	scanf("%d %d",&N,&Q);
	cin.ignore();
	
	string s;
	string q;
	
	vector<string> final;
	vector<string> query;
	
	for (int i=0;i<N;i++){ // Takes all the entries as input in final
		getline(cin,s);
		final.push_back(s);
	}
	
	for (int i=0;i<Q;i++){ // Entry input for queries
		getline(cin,q);
		query.push_back(q);
	}
	
	
	int k=0;
	int p=0;
	int counter=0;
	int len=0;
	string curr_que("abc");
	string attr("cde");
	int index=0;
	int len_attr=0;
	int attr_end=1;
	string c_one;
	int len_store=0;
	int counter_final=0;
	int indexspace=0;
	
	string int1;
	
	for (int i=0;i<Q;i++) // Go through each query
	{
		curr_que=query[i];
		vector<string> store;
		string final_print;
		len=curr_que.length();
		
		k=0;
		p=0;
		counter=0;
		counter_final=0;
		attr_end=1;
		
		
		if (curr_que.find("~")!=string::npos) // Check if ~ present. 
		{
			do {
				int1=curr_que.substr(3+5*(k),1);
				store.push_back(int1);
				k=k+1;
			} while (curr_que[4+5*(k-1)]!='~'); //If present, it is valid and store all the indices of that query

		
			len_store=store.size();
			
			while (p<N)
			{//Parse through the entries N. Check if all the indices of query i stored above are present in N entries

				if (find(store.begin(),store.end(),final[p].substr(4,1))!=store.end())
				{
					counter=counter+1;
					if (counter==len_store) // Valid
					{
						attr=curr_que.substr(curr_que.find("~")+1);
						// Find attribute name in query
						
						if (final[p].find(attr)!=string::npos) 
						// Check if attribute name is present in entry p of N
						{
							indexspace=final[p].find(" ");
							index=final[p].find(attr,indexspace);
							// We start after the first space, that is after tag1
							len_attr=attr.length();
							
							while (true)
							{
							
								c_one=final[p][index+len_attr-1+3+attr_end];
							
							
								if (c_one=="\"") 
								// starting point of attribute value " and stopping at "
								{
									counter_final=counter_final+1;
								}
							
								if (counter_final==2)
								{
									if (final_print.length()>0)
									{
										cout << final_print << endl;
									}
									else // if ended suddenly like ""
									{
										cout << "Not Found!" << endl;
									}
									break;
								}
							
								if (attr_end>1)
								{
									final_print.append(c_one);
								}
							
								attr_end=attr_end+1;
							}
							
						}
						else
						{
							cout << "Not Found!" << endl;
						}
					}
				}
						
				else
				{
					if (p==(N-1) && counter!=len_store)
					{
						cout << "Not Found!" << endl;
					}
						
				}
				p=p+1;
			}
	}
	
	else
	{
		cout << "Not Found!" << endl;
	}	
	}
	
	return 0;
}



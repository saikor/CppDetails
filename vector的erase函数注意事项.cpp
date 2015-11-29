/*
  Name: 测试vector的erase函数
  Discription: 由于vector在使用erase(vector<T>::iterator it) 时，会导致 it指向的位置发生变化，
               导致跳过或漏删的情况，这里明确一下。 
*/
#include <iostream>
#include <vector>
using namespace std;

void test_erase(vector<int> &vec)
{
    /*
    输入：4 5 7 50
    分析：根据输出结果，erase(it) 之后，5之后的元素前移，即元素变为4 7 50，it指向7，所以位置(2) 会输出7
    当遇到50时，元素变为4 7，it指向end()。 
    */
    vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end();)//打印结果 5 size=[4] size=[3] 7 50 size=[3] size=[2] 50 50  -869179998
    {
           if(*it == 5 || *it == 50)
           {      
                  cout << *it << endl;//第一次 5  第二次 50
                  cout << "size=[" << vec.end() - vec.begin() << "]" << endl;
                  vec.erase(it);//vs环境下要使用it = vec.erase(it) 
                  cout << "size=[" << vec.end() - vec.begin() << "]" << endl; 
                  if(it == vec.end())//第二次 //vs环境下，这里无法执行 
                  {
                        cout << *it++ << endl;//50
                        cout << *it++ << endl;//50 这里不清楚为啥还有个50 
                        cout << *it << endl;
                        it = vec.end();//终止循环 
                  }
                  else
                      cout << *it << endl;//第一次 7 (2)
                  
           }
           else 
           {                      
                 it++;                
           }    
    }          
}
void EraseA(vector<int> &vec)
{
     /*example: 4 5 7 5*/
     vector<int>::iterator it, it1;
     for(it = vec.begin(); it != vec.end();)
     {
           if(*it == 5)
           {      
                  it = vec.erase(it);                  
                  //或it1 = it;
                  //it = vec.erase(it1);
           }
           else 
           {                      
                 cout << *it << endl; 
                 it++;                
           }           
     }
}

void EraseB(vector<int> &vec)
{
     /*example: 4 5 7 5*/
     vector<int>::iterator it;
     for(it = vec.begin(); it != vec.end();)
     {
           if(*it == 5)
           {      
                  vec.erase(it);
           }
           else 
           {                      
                 cout << *it << endl; 
                 it++;                
           }           
     }
}

void EraseC(vector<int> &vec)
{
     /*example: 4 5 7 5*/
     vector<int>::iterator it;
     for(it = vec.begin(); it != vec.end();++it)//这里有++ 
     {
           if(*it == 5)
           {      
                  vec.erase(it);
                  it--;//这里就需要后退一个元素 
           }
           else
           {
               cout << *it << endl;
           }
                      
     }
}
int main()
{
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(7);
    //vec.push_back(50);   
    vec.push_back(5);
    //vec.push_back(6);        
    
    //test_erase(vec);
     //EraseA(vec); 
     //EraseB(vec);
     EraseC(vec);
    
  
    cin.get();
    return 0;
}

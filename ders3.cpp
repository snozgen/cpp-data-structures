#include <iostream>
using namespace std;

template< class T>
class vector{
	T* data;
	int cap;
	int index;
	void growth(){
		if(size() == capacity()){
				cap*=2;
				T*tmp = new T[cap];
				for(int i =0; i <size();i++){
				tmp[i] = data[i];
				}
				delete[] data;
                                data = tmp;

				}
	}
	
	void shrink(){
	if(size() <= capacity()/2){
	cap/=2;
	T* tmp = new T[cap];
	for(int i=0;i<size(); i++){
	tmp[i] = data[i];
	}
	delete[] data;
	data = tmp;
	}
	}

	void reset(int index = 0, int cap = 1){
		delete[] data;
		data = NULL;
		this -> index = index;
		this -> cap = cap;
	}
	public:
	vector() : data(nullptr), cap(1), index(0){
		data = new T[cap];
	}
	~vector(){
	if(data)	delete[] data;
	}
	int size()const{ return index;
	}
	int capacity()const {return cap; }

	void push_back(const T& value){
	growth();
		data[index++] = value;
	}
	void pop_back(){
		if(isEmpty())
			throw "Error: Vector is Empty";
		index--;
		shrink();
	}

	bool isEmpty()const{
		return size() == 0;
	}
	T front()const{
		if(isEmpty())
			throw"Error : Vector is empty";
		return data[0];
	}
	T back()const{
		if(isEmpty())
			throw"Error: Vector is empty";
		return data[index - 1];
	}
	T* begin()const{
		return data;
	}
	T* end()const{
		return (data + size());
	}
	T& at(int indis){
		if(indis >= 0 && indis < size())
			return data[indis];
		throw " Error : Vector indis overflow";
	}

	T& operator[](int indis){
		return at(indis);
	}
	void clear(){
		reset();
		data = new T[cap];
	}


};
int main(){
	vector<int> v;
//	cout<< v.capacity() << endl;
//	cout << v.size() << endl;
//	cout << v.isEmpty() <<endl;
	v.push_back(20);
       v.push_back(100);
	v.push_back(10);
 	v.push_back(45);	
//	cout << v.isEmpty()<< endl;
	  //      cout<< v.capacity() << endl;
       // cout << v.size() << endl << endl;
//	cout << v.begin() << endl;
	//cout << v.end()<< endl << endl;
	
	cout << *v.begin() << endl;
	cout << *v.end() << endl;

	cout <<endl << endl << endl;


	int* begin = v.begin();
	int* end = v.end();
	while(begin != end ){
		cout << *begin << "";
		begin++;
	}
	
	cout << endl;
	try{
	v.at(3) = 50;
	}
	catch(const char* exception){
		cout << exception <<endl;
	}
	begin = v.begin();
	while(begin !=end ){
		cout << *begin << "";
		begin++;
	}
	cout << v[2];

	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << "vector sonu " <<endl;
}

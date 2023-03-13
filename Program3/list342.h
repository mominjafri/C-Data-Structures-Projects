#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template<class T>

class List342{
    public:
    //Constructors
    List342() { 
        head_ptr = nullptr; //declare headptr to null upon constructor implementation
    }

    List342(const List342<T> &list){
        head_ptr = nullptr;
        *this = list;

    }

    ~List342(){ //deconstructor
        DeleteList(); //call upon DeleteList method for deconstructor

    }

     bool BuildList(string file_name){
        ifstream file; //initialize ifstream variable
        file.open(file_name); //open file
        if(!file){ //if vile is not valid
            cout << "File not valid" << endl;
            return false;
        }
        T file_obj;
        //this loop has an O(n^2) runtime since it uses nested loops
        while(!file.eof()){ //as long as it doesn't reach the end of the file
            file >> file_obj;
            Insert(&file_obj); //call upon Insert method 
        }
        file.close();
        return true;
     }

     bool Insert(T *obj){
        if(obj == nullptr){
            return false;
        }

        if(Peek(*obj, *obj)){ //call upon Peek method if objects are equal to each other
            return false;
        }
        Node *insertNode = new Node;
        T *insertData;
        insertData = new T;
        *insertData = *obj; //set insertData to pointer object
        insertNode->data = insertData; //insertData equal to template data
        if(head_ptr == nullptr){
            head_ptr = insertNode; //set insertNode to headpointer if equal to null
            return true;
        } else if(*(insertNode->data) < *(head_ptr->data)) {//set condition if insertNode data is less than headpointer's data
            insertNode->next = head_ptr; 
            head_ptr = insertNode; //go to next node and set it equal to headpointer
            return true; 
        } else {
            Node *trackingPtr; //create new node and set it to head pointer
            trackingPtr = head_ptr;
            while ((trackingPtr->next != nullptr)&&(*(insertNode->data) > *(trackingPtr->next->data))){ //set condition if next node equals null AND if insertNode's data is greater than the next data for trackingPtr
                trackingPtr = trackingPtr -> next;

            }
            insertNode -> next = trackingPtr -> next; 
            trackingPtr -> next = insertNode; //next node for trackingPointer set equal to insertNode
        }
        return true;
     }

     bool Remove(T target, T &result){
        if(head_ptr == nullptr){ //check condition to see if head pointer is equal to null, return false accordingly
            return false;
        }

        Node *currentPtr; 
        currentPtr = head_ptr;
        if(*(head_ptr->data) == target){ //if headpointer's data is equal to template object
            head_ptr = head_ptr -> next;
            result = *(currentPtr -> data);
            delete currentPtr -> data; //delete the data 
            currentPtr->data = nullptr; //set it to null
            currentPtr->next = nullptr;
            delete currentPtr; 
            currentPtr = nullptr;
            return true;
        }

        currentPtr = head_ptr;
        Node *trackingPtr;
        while(currentPtr -> next != nullptr && *(currentPtr -> next -> data) < target){ //set condition if currentpointer's next node is not null and if current pointer's next data has a value less than target
            currentPtr = currentPtr -> next; //set currentPointer to its next node
        }

        if((currentPtr -> next) == nullptr){ 
            return false;
        } else { //if currentpointer's next node is not null
            trackingPtr = currentPtr -> next;
            result = *(trackingPtr -> data);
            currentPtr -> next = currentPtr -> next -> next; 
            delete trackingPtr -> data;
            trackingPtr-> data = nullptr;
            delete trackingPtr;
            trackingPtr = nullptr;
            return true;
        }

     }

     bool Peek(T target, T &result) const{
        if(head_ptr == nullptr){
            return false;
        } 
        Node *currentPtr;
        currentPtr = head_ptr;
        while(currentPtr != nullptr){ //as long as current is not equal to null
            if(*(currentPtr -> data) == target){ 
                result = *(currentPtr -> data); //set template object to current pointer's data
                return true;
            } else {
                currentPtr = currentPtr -> next; 
            }
        }
        return false;
     }

     int Size() const{
        int count = 0; //initialize int variable
        Node* tracker; //create new node
        tracker = head_ptr; //set it to headpointer

        if(tracker == nullptr){ //if tracker is null, return 0
            return count;
        }

        while(tracker -> next != nullptr){ //as long as tracker and its next node is not null, repeatedly add 1 to count
            count++;
            tracker = tracker -> next;
        }

        return count;
     }

     bool isEmpty() const{
        return(head_ptr == nullptr); //will return true if headpointer is null

     }

     void DeleteList(){
        Node *temp; //create new node
        while(head_ptr != nullptr){ //as long as headpointer is not null...
            temp = head_ptr; //set new node to headpointer
                head_ptr = head_ptr -> next; //call upon next node
                delete temp -> data; //delete data
                delete temp; //delete node
        }
        head_ptr = nullptr; //now that list is deleted, headpointer is now null
     }

     bool Merge(List342 &list1){
        if(this == &list1 || list1.head_ptr == nullptr){  //return false if parameter is equal to referenced (copied) list or if headpointer is null
            return false;
        } 

        if(head_ptr == nullptr){
            head_ptr = list1.head_ptr;
            list1.head_ptr = nullptr; //set list1's headpointer to null if headpointer is null
            return true;

        }

        Node *trackingNode2; //create new node
        trackingNode2 = list1.head_ptr; 
        if((*head_ptr -> data) >= *(trackingNode2 -> data)){ 
            list1.head_ptr = list1.head_ptr -> next;//set list1 headpointer to next node
            if(*head_ptr -> data == *(trackingNode2 -> data)){ //delete nodes if next nodes are equal to each other
                delete(trackingNode2 -> data);
                delete trackingNode2;
            } else {
                trackingNode2 -> next = head_ptr;
                head_ptr = trackingNode2; //set trackingnode2 to next node
            }
        }

        Node *trackingNode;
        trackingNode = head_ptr;
        while (list1.head_ptr != nullptr){ //as long as list1's head pointer is not null
            if(trackingNode -> next != nullptr){ //go through list, as long as next node is not null, set trackingnode2 to list1 headpointer
                trackingNode2 = list1.head_ptr;
                if(*(trackingNode2 -> data) < *(trackingNode -> next -> data)){
                    list1.head_ptr = list1.head_ptr->next;
                        trackingNode2->next = trackingNode->next;
                        trackingNode->next = trackingNode2;
                        trackingNode = trackingNode2;
                        trackingNode2 = nullptr;
                } else if (*(trackingNode2 -> data) == *(trackingNode -> next -> data)) { //delete node if next data is equal
                    list1.head_ptr = list1.head_ptr -> next;
                        delete trackingNode2->data;
                        delete trackingNode2;
                        trackingNode2 = nullptr;
                } else {
                    trackingNode = trackingNode->next; //if condition is not met, trackingNode is equal to its next node
                }
                
            } else {
                trackingNode -> next = trackingNode2;
                list1.head_ptr = nullptr;
                return true;
            }
        }

        return true;
     }

     List342 operator+(const List342 &list) const{
        List342 <T> temp_list; //create new template object
        temp_list = *this; //template object is equal to referenced parameter
        temp_list += list; //add to each other
        return temp_list;

     }

     List342& operator+=(const List342 &list){
        List342<T> list_copy; //create a copy
        list_copy = list; //set it equal to parameter value
        Merge(list_copy); //merge lists
        return *this;

     } 



     bool operator==(const List342 &list) const{
        if(((head_ptr == nullptr) && (list.head_ptr != nullptr)) || ((head_ptr != nullptr) && (list.head_ptr == nullptr))){ //if either head pointer is equal to null (while other is not) or list's headpointer is null, return false
            return false;
        }

        Node *tracker1, *tracker2; //create two tracker nodes, one for headpointer the other for list headpointer
        tracker1 = head_ptr; 
        tracker2 = list.head_ptr;
        while(tracker1 != nullptr && tracker2 != nullptr){ //if both pointers are null
            if(*(tracker1 -> data) == *(tracker2 -> data)){ //if data is same
                tracker1 = tracker1 -> next;
                tracker2 = tracker2 -> next;
            } else {
                return false;
            }
        } if((tracker1 == nullptr && tracker2 == nullptr) || (tracker1 != nullptr && tracker2 != nullptr)){
            return true;
        }
        return false;
     }

     bool operator!=(const List342 &list) const{
        return !(*this == list); //returns true if given parameter is not equal to list
     }

     List342& operator=(const List342 &list){
        if(this == &list){ //return parameter if equal to referenced object
            return *this;
        }
        
        DeleteList(); //call upon method
        if(list.Size() == 0){
            return *this;
        }
        Node *assignedNode = new Node;
        Node *tracker, *current;
        T *assignedT = new T;
        *assignedT = *(list.head_ptr -> data); //assign new template to next list's headpointer's data
        assignedNode -> data = assignedT; //assignedNode's data set equal to template
        assignedNode -> next = nullptr; //not necessary but just to be safe
        head_ptr = assignedNode;
        tracker = head_ptr;
        current = list.head_ptr -> next; 
        while(current != nullptr){ //current is set to next headpointer of list, so as long as its not null...
            assignedNode = new Node; //allocate to new
            assignedT = new T;
            *(assignedT) = *(current -> data);
            assignedNode -> data = assignedT;
            assignedNode -> next = nullptr;
            tracker -> next = assignedNode;
            tracker = tracker -> next;
            current = current -> next;

        }
        return *this;

     }


     friend ostream& operator<<(ostream& os, const List342<T> &list){
        //if(list2.isEmpty()) -- this method could also be used
        if(list.Size() == 0){ 
            os << "List is Empty" << endl; //output that list is empty to console if there is nothing in the list
            return os;

        } 

        Node *current_ptr; //create a "current pointer"
        current_ptr = list.head_ptr; //set it equal to the list's headptr
        while(current_ptr != nullptr){ //set condition that as long as current is not equal to null, loop runs
            os << *(current_ptr -> data); //output the current pointers data
            current_ptr = current_ptr -> next; 
        }
        return os;

     }

     private:
     struct Node{ //structure declaration
        T *data; 
        Node *next;
     };
     Node *head_ptr; 
};

class Child{
    public:
    Child()
    {
        age_ = 0;   
    }

    Child(string first_name, string last_name, int age)
    {
        first_name_ = first_name;
        last_name_ = last_name;
        age_ = age;
    }
    Child(string first_name, string last_name)
    {
        first_name_ = first_name;
        last_name_ = last_name;
        age_ = 0;
    }
    string name() const
    {
        return (first_name_ + last_name_);
    }

    int age() const
    {
        return age_;
    }
    void set_first_name(const string &name)
    {
        first_name_ = name;
    }         
    void set_last_name(const string &name)   
    {
        last_name_ = name;
    }
// Operator Overloads
    bool operator==(const Child &child) const
    {
        return ((first_name_ == child.first_name_) &&
        (last_name_ == child.last_name_) &&
        (age_ == child.age_));  
    }

    bool operator!=(const Child &child) const
    {
        return !(*this == child);
    }
    bool operator<(const Child &child) const
    {
        //Compare last names, then first names, then age.
        if (last_name_ < child.last_name_)
    {
        return true;
    }
        else if (last_name_ > child.last_name_)
    {
        return false;
    }
        if (first_name_ < child.first_name_)
    {
        return true;
    }   
        else if (first_name_ > child.first_name_)
    {
        return false;
    }
        return (age_ < child.age_);
    }

    bool operator<=(const Child &child) const
    {
        return ((*this == child) || (*this < child));
    }
    bool operator>(const Child& child) const
    {
        return !(*this <= child);
    }
    bool operator>=(const Child &child) const
    {
        return ((*this == child) || (*this > child));
    }
   friend ostream& operator<<(ostream &stream, const Child &child)
    {
        stream << child.first_name_ << child.last_name_ << child.age_;
        return stream;
    }
    friend istream& operator>>(istream &stream, Child &child)  
    {
        stream >> child.first_name_;
        stream >> child.last_name_;
        stream >> child.age_;
        return stream;
    }

    private:
    int age_;
    string first_name_;
    string last_name_;

    
};


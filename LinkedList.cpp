#include "LinkedList.h"

LinkedList::LinkedList() {
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}


LinkedList::LinkedList(const LinkedList& list) {
    this->length = list.length;
    this->head = list.head;
    this->tail = list.tail;
}
LinkedList::LinkedList(LinkedList &&list) {
    this->length = std::move(list.length);
    this->head = std::move(list.head);
    this->tail = std::move(list.tail);


    list.length = 0;
    list.tail = nullptr;
    list.head = nullptr;

}
LinkedList& LinkedList::operator=(const LinkedList &list) {
    this->length = list.length;
    this->head = list.head;
    this->tail = list.tail;
    return *this;
}
LinkedList& LinkedList::operator=(LinkedList &&list) {
    this->length = std::move(list.length);
    this->head = std::move(list.head);
    this->tail = std::move(list.tail);


    list.length = 0;
    list.tail = nullptr;
    list.head = nullptr;
    return *this;
}
void LinkedList::pushTail(string _name, float _amount) {
    Node* node = new Node(_name, _amount);
    if(!this->tail) {
        this->tail = std::move(node);
        this->head=std::move(node);
        this->length++;
        return;

    }
    this->tail->next = std::move(node);
    this->tail=std::move(node);
    this->length++;

}
void LinkedList::updateNode(string _name, float _amount){
    Node* temp = this->head;
    while(temp){

        if(temp->name==_name){
            temp->amount=_amount;
            return;
        }
        else
            temp = temp->next;
    }
    if(temp->name==_name){
        temp->amount=_amount;
    }


}
LinkedList::~LinkedList(){
    delete head;
}
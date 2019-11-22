#include "SurveyClass.h"

SurveyClass::SurveyClass() {
    this->members = new LinkedList();
}
SurveyClass::SurveyClass(const SurveyClass &other) {
    this->members = new LinkedList(*(other.members));
}
SurveyClass::SurveyClass(SurveyClass &&other) {
    this->members = std::move(other.members);
    other.members = nullptr;
}
SurveyClass& SurveyClass::operator=(const SurveyClass &list) {
    delete this->members;
    this->members = new LinkedList(*(list.members));
    return *this;
}
SurveyClass& SurveyClass::operator=(SurveyClass &&list) {
    delete this->members;
    this->members = std::move(list.members);
    list.members = nullptr;
}
SurveyClass::~SurveyClass() {
    delete members;
}
float SurveyClass::calculateAverageExpense() {

    if(this->members->head== nullptr){
        return 0.00f;
    }
    Node* temp = this->members->head;
    float count = 0;
    float total = 0;
    while(temp){
        total += temp->amount;
        count++;
        temp = temp->next;
    }
    float result = (int)((total/count)*100)/100.0;

    return result;


}
float SurveyClass::calculateMaximumExpense() {

    if(this->members->head== nullptr){
        return 0.00f;
    }
    Node* temp = this->members->head;
    float max = temp->amount;

    while(temp){
        if(temp->amount>max) {
            max = temp->amount;
        }
        temp = temp->next;
    }
    float result = (int)(max*100)/100.0;
    return result;

}
float SurveyClass::calculateMinimumExpense() {

    if(this->members->head== nullptr){

        return 0.00f;
    }
    Node* temp = this->members->head;
    float min = temp->amount;

    while(temp){
        if(temp->amount< min) {
            min = temp->amount;
        }
        temp = temp->next;
    }
    float result = (int)(min*100)/100.0;
    return result;

}
void SurveyClass::handleNewRecord(string _name, float _amount) {

    if(!this->members->head){

        this->members->pushTail(_name,_amount);
        return;
    }
    Node* iter = this->members->head;
    while(iter){
        if(iter->name==_name){

            this->members->updateNode(_name, _amount);
            return;
        }
        else
            iter = iter->next;
    }

    this->members->pushTail(_name,_amount);
}
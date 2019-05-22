#include <iostream>
#include <exception>
using namespace std;
class StudentNameException : public exception
{
    string name;
    public:
        const char * what()
        {
            return "Wrong name ";
        }
        void getName()
        {
            cout<<"Student name is  "<<name<<endl;
        }
        void setName(string n)
        {
            this->name=move(n);
        }
};
class StudentSurnameException : public exception
{
    string surname;
public:
    const char * what()
    {
        return "Wrong surname ";
    }
    void getSurname()
    {
        cout<<"Student surname is  "<<surname<<endl;
    }
    void setSurname(string s)
    {
        this->surname=move(s);
    }
};
class StudentAgeException: public exception
{
    int age;
public:
    const char * what()
    {
        return "Wrong age ";
    }
    void getAge()
    {
        cout<<"Student age is  "<<age<<endl;
    }
    void setAge(int a)
    {
        this->age=a;
    }
};
class StudentFieldException : public exception
{
    string field;
public:
    const char * what()
    {
        return "Wrong field ";
    }
    void getField()
    {
        cout<<"Student field is  "<<field<<endl;
    }
    void setField(string f)
    {
        this->field=move(f);
    }
};
class Student
{
    string name;
    string surname;
    int age;
    string field;
public:
    Student(string n , string s, int a, string f)
    {
        name=move(n);
        surname=move(s);
        age=a;
        field=move(f);
    }
    void Add()
    {
        cout<<"Type name "<<endl;
        cin>>name;
        cout<<"Type surname "<<endl;
        cin>>surname;
        cout<<"Type age "<<endl;
        cin>>age;
        cout<<"Type field "<<endl;
        cin>>field;
        for (int i = 1; i < name.length();i++) {
            if (name[0] < 65 or name[0] > 90 or name.length() == 0 or name[i]<97 or name[i]>122 ) {
                StudentNameException exc;
                exc.setName(name);
                throw exc;
            }
        }
        for (int i = 1; i < surname.length();i++) {
            if (surname[0] < 65 or surname[0] > 90 or surname.length() == 0 or surname[i]<97 or surname[i]>122 ) {
                StudentSurnameException exc;
                exc.setSurname(surname);
                throw exc;
            }
        }
        if(age<10 or age>100)
        {
            StudentAgeException exc;
            exc.setAge(age);
            throw exc;
        }
        if(field!="IT" or field!="maths" or field!="economy" or field!="philosophy")
        {
            StudentFieldException exc;
            exc.setField(field);
            throw exc;
        }
    }
};
int main() {
    Student student("Paul", "Han", 19, "IT");
    while (true)
    {
        try {
            student.Add();
            break;
        }
        catch (StudentNameException &exc) {
            cout << exc.what() << endl;
            exc.getName();
        }
        catch (StudentSurnameException &exc) {
            cout << exc.what() << endl;
            exc.getSurname();
        }
        catch (StudentAgeException &exc) {
            cout << exc.what() << endl;
            exc.getAge();
        }
        catch (StudentFieldException &exc) {
            cout << exc.what() << endl;
            exc.getField();
        }
        cout<<"Oh shit, here we go again"<<endl;
    }
    cout<<"Finally no error occurred"<<endl;
    return 0;
}
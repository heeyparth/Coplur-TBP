#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IEmployee {
public:
    virtual double calculateSalary() = 0; 
    virtual void getDetails() = 0;        
       
};


class PermanentEmployee : public IEmployee {
private:
    string name;   
    double basicPay; 
    double bonus;   

public:
    
    PermanentEmployee(string empName, double empBasicPay, double empBonus) {
        name = empName;
        basicPay = empBasicPay;
        bonus = empBonus;
    }

   
    double calculateSalary() override {
        return basicPay + bonus;
    }

   
    void getDetails() override {
        cout << "Permanent Employee: " << name << endl;
        cout << "Basic Pay: " << basicPay << ", Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateSalary() << endl << endl;
    }
};


class ContractEmployee : public IEmployee {
private:
    string name;       
    double hourlyRate;  
    int hoursWorked;    

public:
    ContractEmployee(string empName, double empHourlyRate, int empHoursWorked) {
        name = empName;
        hourlyRate = empHourlyRate;
        hoursWorked = empHoursWorked;
    }

    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }

    
    void getDetails() override {
        cout << "Contract Employee: " << name << endl;
        cout << "Hourly Rate: " << hourlyRate << ", Hours Worked: " << hoursWorked << endl;
        cout << "Total Salary: " << calculateSalary() << endl << endl;
    }
};


class PayrollService {
public:

    void generatePayroll(vector<IEmployee*> employees) {
        cout << "Payroll Report:" << endl;
        for (int i = 0; i < employees.size(); i++) {
            employees[i]->getDetails(); 
        }
    }
};

int main() 
{

    PermanentEmployee emp1("Parth Shrivastava", 50000, 5000);
    ContractEmployee emp2("Abhijeet Thakur", 100, 160);

    vector<IEmployee*> employees; 
    employees.push_back(&emp1);
    employees.push_back(&emp2);

    PayrollService payrollService;
    payrollService.generatePayroll(employees);

    return 0; 
}

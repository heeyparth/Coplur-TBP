const express = require("express");
const fs = require("fs");

const app = express();
const PORT = 8000;

const filePath = "./MOCK_DATA.json";
app.use(express.json());

const loadEmployees = () => JSON.parse(fs.readFileSync(filePath, "utf-8"));
const saveEmployees = (data) => fs.writeFileSync(filePath, JSON.stringify(data, null, 2), "utf-8");


// get all employees
app.get("/api/employees", (req, res) => {
  const employees = loadEmployees();
  res.json(employees);
});


//get employee by id
app.get("/api/employees/:id", (req, res) => {
  const employees = loadEmployees();
  const id = parseInt(req.params.id);
  const employee = employees.find((emp) => emp.id === id);

  if (!employee) {
    return res.status(404).json({ message: "Employee not found" });
  }

  res.json(employee);
});


// add new employee
app.post("/api/employees", (req, res) => {
  const employees = loadEmployees();
  const { name , email, salary, position } = req.body;

  if (!name || !email) {
    return res.status(400).json({ message: " Name and email are required" });
  }

  const newEmployee = {
    id: employees.length > 0 ? employees[employees.length - 1].id + 1 : 1,
    name,
    email,
    position: position || null,
    salary: salary || null
    
  };

  employees.push(newEmployee);
  saveEmployees(employees);

  res.status(201).json(newEmployee);
  res.json({ message: "new employee added sucessfully !" });
});


// edit employee 
app.put("/api/employees/:id", (req, res) => {
  const employees = loadEmployees();
  const id = parseInt(req.params.id);
  const { name, email, salary, position } = req.body;

  const employeeIndex = employees.findIndex((emp) => emp.id === id);
  if (employeeIndex === -1) {
    return res.status(404).json({ message: "Employee not found" });
  }

  employees[employeeIndex] = {
    ...employees[employeeIndex],
    name: name || employees[employeeIndex].name,
    email: email || employees[employeeIndex].email,
    salary: salary || employees[employeeIndex].salary,
    position: position || employees[employeeIndex].position,
  };

  saveEmployees(employees);

  res.json(employees[employeeIndex]);
});


// delete employee by id
app.delete("/api/employees/:id", (req, res) => {
  const employees = loadEmployees();
  const id = parseInt(req.params.id);

  const filteredEmployees = employees.filter((emp) => emp.id !== id);
  if (filteredEmployees.length === employees.length) {
    return res.status(404).json({ message: "Employee not found" });
  }

  saveEmployees(filteredEmployees);

  res.json({ message: `Employee with id ${id} deleted successfully` });
});


app.listen(PORT, () => {
  console.log(`Server is running on ${PORT}`);
});
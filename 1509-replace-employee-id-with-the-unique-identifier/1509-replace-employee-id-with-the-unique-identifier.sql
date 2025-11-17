select e.name as name , eu.unique_id as unique_id
from employees as e
left join employeeuni as eu on e.id = eu.id;
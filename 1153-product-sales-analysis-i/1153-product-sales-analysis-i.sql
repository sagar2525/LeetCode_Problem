select p.product_name as product_name, s.year as year, s.price as price
from sales as s
left join product as p on p.product_id = s.product_id;
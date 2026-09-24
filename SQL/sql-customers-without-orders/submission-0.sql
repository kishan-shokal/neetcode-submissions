-- Write your query below

SELECT cs.name
FROM customers AS cs
LEFT JOIN orders AS od
    ON cs.id = od.customer_id
where od.customer_id is null;

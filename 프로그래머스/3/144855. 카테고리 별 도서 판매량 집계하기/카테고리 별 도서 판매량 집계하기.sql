SELECT
    category,
    sum(sales) as total_sales
FROM 
    BOOK AS B
JOIN BOOK_SALES AS BS
ON B.BOOK_ID = BS.BOOK_ID
WHERE
    YEAR(SALES_DATE) = 2022
AND
    MONTH(SALES_DATE) = 1
GROUP BY
    CATEGORY
order by
    category
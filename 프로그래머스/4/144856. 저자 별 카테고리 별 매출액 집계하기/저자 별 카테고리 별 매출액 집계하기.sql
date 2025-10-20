select

    b.AUTHOR_ID,
    AUTHOR_NAME,
    CATEGORY,
    sum(price * sales) as TOTAL_SALES
from
    book as b
join author as a using(author_id)
join book_sales as c using(book_id)
where
    year(SALES_DATE) = 2022 and month(SALES_DATE) = 1
group by
    author_id, CATEGORY
order by
    author_id, category desc
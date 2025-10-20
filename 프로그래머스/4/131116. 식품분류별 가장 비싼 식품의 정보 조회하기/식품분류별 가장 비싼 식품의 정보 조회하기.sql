select
    CATEGORY,
    price as MAX_PRICE,
    PRODUCT_NAME
from
    FOOD_PRODUCT
where  (category, price) in (
        select
            CATEGORY,
            max(price)
        from
            FOOD_PRODUCT
        where
            category in ('과자', '국', '김치', '식용유')
        group by
            CATEGORY
        )
order by
    MAX_PRICE desc
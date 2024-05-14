SELECT YEAR(O.SALES_DATE), MONTH(O.SALES_DATE), U.GENDER, COUNT(DISTINCT(USER_ID))
FROM ONLINE_SALE AS O JOIN USER_INFO U USING(USER_ID)
WHERE U.GENDER IS NOT NULL
GROUP BY MONTH(O.SALES_DATE), gender
ORDER BY 1,2,3


# SELECT YEAR(O.sales_date), MONTH(O.sales_date), U.gender, count(DISTINCT(user_id))
#     FROM online_sale O
#         JOIN user_info U
#         USING(user_id)
#     WHERE U.gender is not NULL
#     GROUP BY MONTH(O.SALES_DATE), gender
#     ORDER BY 1, 2, 3
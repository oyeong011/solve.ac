select
    count(*) as FISH_COUNT,
    max(length) as MAX_LENGTH,
    FISH_TYPE
FROM
    FISH_INFO
group by
    fish_type
having
    avg(ifnull(length, 10))>=33
order by
    fish_type
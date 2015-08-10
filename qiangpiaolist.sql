SELECT hd.id as huodong_id, hd.type as huodong_type, hd.icon, hd.title, dd.name as huodong_didian, 
piao.time as qiangpiao_start_time, piao.sy_count as nums, piao.id as piao_id FROM huodong as hd 
LEFT JOIN huodong_didian as dd ON dd.id = hd.didian  LEFT JOIN piao ON piao.huodong_id = hd.id  
WHERE hd.riqi >= curdate()  AND piao.type  = '1' AND '2015-08-10 18:34:19'<= hd.qiangpiao_end_time  
AND hd.qp_type  = '1' AND hd.city_code  = '310100' GROUP BY hd.id ORDER BY piao.time asc 

UNION 

SELECT hd.id as huodong_id, hd.type as huodong_type, hd.icon, hd.title, dd.name as huodong_didian, 
piao.time as qiangpiao_start_time, piao.sy_count as nums, piao.id as piao_id FROM huodong as hd 
LEFT JOIN huodong_didian as dd ON dd.id = hd.didian  LEFT JOIN piao ON piao.huodong_id = hd.id  
WHERE hd.city_code  != '310100' AND piao.type  = '1' AND hd.riqi >= curdate()  
AND '2015-08-10 18:36:48'<= hd.qiangpiao_end_time  AND hd.qp_type  = '1' GROUP BY hd.id 
ORDER BY qiangpiao_start_time desc LIMIT 5

## 설명
### 이건 트리구조다
트리 구조라고 생각하고, 루트 노드인 것만 구하면 된다. 그 말인 즉슨, 부모 ID가 없는 경우면 루트이기 때문에 이 점을 이용하면 된다.

### 구현하기
SQL에서도 재귀문도 있지만 이 경우엔 간단하다. 부모 ID가 별도 태이블이 존재한다. 따라서 기존 `ITEM_INFO` 태이블에서 부모 정보가 있는 `ITEM_TREE` 태이블을 `LEFT OUTER JOIN` 하면 된다. 그 이유는? 이걸 하지 않을 경우 부모 아이디가 없으면 join에서 제외시키기 떄문!

## 코드
```sql
WITH tb AS (
    SELECT o.ITEM_ID, 
           o.ITEM_NAME,
           o.RARITY,
           e.PARENT_ITEM_ID
      FROM ITEM_INFO o
      LEFT OUTER JOIN ITEM_TREE e
        ON o.ITEM_ID = e.PARENT_ITEM_ID
)
SELECT tb.ITEM_ID,
       tb.ITEM_NAME,
       tb.RARITY
  FROM tb
 WHERE tb.PARENT_ITEM_ID IS NULL
 ORDER BY tb.ITEM_ID DESC;
```

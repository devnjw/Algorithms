SELECT ANIMAL_OUTS.ANIMAL_ID, ANIMAL_OUTS.NAME
FROM ANIMAL_OUTS
Left Join ANIMAL_INS
On ANIMAL_INS.ANIMAL_ID = ANIMAL_OUTS.ANIMAL_ID
Where ANIMAL_INS.ANIMAL_ID is Null

ll1 = [
    [ ],
    [ 0, 1, 2 ],
    [ 0, 1, 4 ],
    [ 0 ],
    [ 0, 1, 3 ],
    [ 0, 1, 2 ],
    [ 0, 2 ],
]

ll2 = [
    [],
    [0,1,2,3],
    [0,1,4,5],
    [0],
    [0,1,3,6],
    [0,1,2,4],
    [0,1,2],
]

ll3 = [
    [],
	[0,1,2]	,
    [0,1,4],
    [],
    [0,1,3,4,5],
    [0,1,2,4],
    [0,1,2],
]

for ll in ll3:
    count = 0
    for bit in ll:
        count += pow(2, bit)
    print(f'{count}', end='\t')
timeLimit = 2000
memoryLimit = 262144
testId = 0

def gen(subtaskId : int, subtaskName : str, testpointNum : int, score : int) -> None:
    global testId
    for i in range(1, testpointNum + 1):
        testId += 1
        print(f"{f'{testId:03d}'}_{f'{subtaskId:03d}'}_{subtaskName}_{f'{i:03d}'}.in:")
        print(f"    timeLimit: {timeLimit}")
        print(f"    memoryLimit: {memoryLimit}")
        print(f"    score: {score}")
        print(f"    subtaskId: {subtaskId}")
        print()

gen(0, "small", 4, 13)
gen(1, "square_rand", 8, 21)
gen(2, "spec_chain", 6, 12)
gen(3, "spec_star", 7, 12)
gen(4, "big_rand", 15, 42)
gen(4, "big_star_like", 5, 42)
gen(4, "big_chain_like", 5, 42)

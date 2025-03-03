class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        size = len(gas)
        for i in range(size):
            index = i
            tank =0
            if(gas[i]>=cost[i]):
                while True:
                    if (tank+gas[index]) >= cost[index]:
                        tank = tank + gas[index] - cost[index]
                        index +=1
                        if index >= size:
                            index -= size
                        if index == i:
                            return i
                    else:
                        break
        return -1

def main():
    gas  = [3, 1, 1]
    cost = [1, 2, 2]
    sol = Solution()
    solution = sol.canCompleteCircuit(gas, cost)
    print(solution)


if __name__ == "__main__":
    main()
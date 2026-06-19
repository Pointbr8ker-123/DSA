def longestCommonPrefix(strs):
    res = ""
    for i in range(len(strs[0])):
        for s in strs: # this is basically saying "for each character in the ith position of the elements in the array... are they the same or not?"
            if i == len(s) or s[i] != strs[0][i]:
                return res
        res += strs[0][i]

    return res

def main():
    strs = ["flower", "flow", "flight"]
    lcp = longestCommonPrefix(strs)
    print(lcp)

main()
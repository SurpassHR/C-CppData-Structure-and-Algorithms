#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getSubString(vector<string> words, int startPos, set<string> &subStrings)
    {
        if (startPos == words.size() - 1) {
            string res;
            for (auto word = words.begin(); word < words.end(); ++word) {
                res.append(*word);
            }
            subStrings.emplace(res);
        }
        for (int i = startPos; i < words.size(); ++i) {
            swap(words[i], words[startPos]);
            getSubString(words, startPos + 1, subStrings);
            swap(words[i], words[startPos]);
        }
    }

    vector<size_t> findMultiple(const string &s, const string &pat)
    {
        vector<size_t> res;
        size_t pos = s.find(pat, 0);
        while (pos != string::npos) {
            res.push_back(pos);
            pos = s.find(pat, pos + 1);
        }
        return res;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        set<int> res;
        set<string> subString;
        getSubString(words, 0, subString);
        for (auto word = subString.begin(); word != subString.end(); ++word) {
            vector<size_t> pos = findMultiple(s, *word);
            res.insert(make_move_iterator(pos.begin()), make_move_iterator(pos.end()));
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main()
{
    vector<string> words = { "dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb" };
    set<string> subStrings;
    Solution s;
    s.getSubString(words, 0, subStrings);
    for (auto iter : subStrings) {
        cout << iter << "\t";
    }
    cout << endl;

    string str = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
    vector<int> res = s.findSubstring(str, words);
    for (auto iter : res) {
        cout << iter << "\t";
    }
    cout << endl;

    cout << endl;
    return 0;
}
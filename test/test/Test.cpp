#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> twoSum(vector<int> nums, int target) {
		vector<int> result;
		int len = nums.size();
		int pair=0, index1=-1, index2=-1;
		map<int, bool> checklist;

		for (int i = 0; i< len; i++){
			int val = nums[i];
			if (checklist[target - val]){
				pair = target - val;
				index2 = i + 1;
				break;
			}
			checklist[val] = true;
		}

		for (int i = 0; i< len; i++){
			if (nums[i] == pair){
				index1 = i + 1;
				break;
			}
		}
		result.push_back(index1);
		result.push_back(index2);
		return result;
	}

	string convert(string s, int numRows) {
		vector<string> pattern(numRows);
		int cicle = numRows * 2 - 2;
		int index;
		for (int i = 0; i < s.length(); i++){
			index = i % cicle;
			index = (index < numRows) ? index : 2*(numRows-1) -index;
			pattern[index].append(s, i, 1);
		}
		string ans;
		for (int i = 0; i < numRows; i++)
			ans.append(pattern[i]);
		return ans;
	}

	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;

		ListNode *slow = head, *fast = head;

		while (fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		slow = slow->next;

		ListNode *nhead = slow;
		
		slow = slow->next;
		nhead->next = NULL;
		while (slow){
			ListNode *temp = slow;
			slow = slow->next;
			temp->next = nhead;
			nhead = temp;
		}

		slow = head;
		while (nhead){
			if (slow->val != nhead->val)
				return false;
			slow = slow->next;
			nhead = nhead->next;
		}
		return true;

	}

	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int sum1 = (C - A)*(D - B) + (G - E)*(H - F);
		int sum2 = (C - A)*(D - B) + (G - E)*(H - F) - (C - E)*(H - B);
		if (C <= E || B <=H)
			return sum1;
		else
			return sum2;

	}
};

int main(){
	Solution *res = new Solution();
	//vector<int> nums;
	//nums.push_back(3);
	//nums.push_back(2);
	//nums.push_back(4);
	//vector<int> answer = res->twoSum(nums, 6);

	//cout << " Index1 = " << answer[0] << "\n Index2 = "<< answer[1] << endl;


	//string a = res->convert("PAYPALISHIRING", 3);

	//cout << "PAYPALISHIRING" << "===> "<<a << endl;

	/*ListNode *test_list;

	test_list = new ListNode(1);
	test_list->next = new ListNode(2);
	test_list->next->next = new ListNode(2);
	test_list->next->next->next = new ListNode(1);

	cout << "Palindrome list: " << res->isPalindrome(test_list) << endl;*/

	cout << "area " << res->computeArea(0,0,0,0,-1,-1,1,1) << endl;

	system("pause");
	return 0;
}
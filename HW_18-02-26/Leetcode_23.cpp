class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.size()==NULL) return 0;
        ListNode* res=lists[0];
        for(int i=1;i<lists.size();i++){
          res=mergeTwoLists(res, lists[i]);
        }
        return res;
    }
};

#ifndef __LINTCODE_0007__
#define __LINTCODE_0007__

#include "data-types.h"

/*@@7. Serialize and Deserialize Binary Tree
Design an algorithm and write code to serialize and deserialize a binary tree.
Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

Example
Example 1:
    Input:{3,9,20,#,#,15,7}
    Output:{3,9,20,#,#,15,7}
    Explanation:
    Binary tree {3,9,20,#,#,15,7},  denote the following structure:
          3
         / \
        9  20
          /  \
         15   7
    it will be serialized {3,9,20,#,#,15,7}

Example 2:
    Input:{1,2,3}
    Output:{1,2,3}
    Explanation:
    Binary tree {1,2,3},  denote the following structure:
       1
      / \
     2   3
    it will be serialized {1,2,3}

Our data serialization use BFS traversal. This is just for when you got Wrong Answer and want to debug the input.
You can use other method to do serializaiton and deserialization.

Notice
    There is no limit of how you deserialize or serialize a binary tree,
    LintCode will take your output of serialize as the input of deserialize, it won't check the result of serialize.
*/
class Solution7 // in lintcode, submit fail:Memory Limit Exceeded!!!!!
{ 
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    std::string serialize(TreeNode* root) 
    {
        std::string result;
        if (!root) {
            return result;
        }

        result += "{";
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                result += "#,";
                continue;
            }

            result += std::to_string(node->val);
            result += ",";

            q.push(node->left);
            q.push(node->right);
        }
        result.pop_back(); //remove last ",".

        while (result.back() == '#') {
            result.pop_back(); //'#'
            result.pop_back(); //','
        }
        result += "}";

        return result;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode* deserialize(std::string& data) 
    {
        if (data.empty() || data[0] == '#' || data[0] == ',' || data == "{}") {
            return nullptr;
        }

        std::vector<std::string> items = getItem(data);

        std::queue<TreeNode*> q;

        TreeNode* head = new TreeNode(stoi(items[0]));
        q.push(head);

        int i = 0, itemsSize = (int)items.size();
        while (i < itemsSize) {
            int len = q.size();
            for (int j = 0; j < len; j++) {
                TreeNode* node = q.front();
                q.pop();

                i++;
                if (i > itemsSize) {
                    node->left = nullptr;
                    break;
                }
                if (items[i] != "#") {
                    node->left = new TreeNode(stoi(items[i]));
                    q.push(node->left);
                }

                i++;
                if (i > itemsSize) {
                    node->right = nullptr;
                    break;
                }
                if (items[i] != "#") {
                    node->right = new TreeNode(stoi(items[i]));
                    q.push(node->right);
                }
            }
        }

        return head;
    }

private:
    std::vector<std::string> getItem(std::string& str) 
    {
        std::vector<std::string> result;
        int index = 0, lastIndex = 0;
        while (index = str.find(',', lastIndex) != std::string::npos) {
            result.push_back(str.substr(lastIndex, index - lastIndex));
            lastIndex = index + 1;
        }

        if (lastIndex != str.size()) {
            result.push_back(str.substr(lastIndex, str.size() - lastIndex));
        }

        return result;
    }
};

#endif


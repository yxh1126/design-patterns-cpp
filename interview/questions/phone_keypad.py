class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False


class T9Dictionary:
    def __init__(self):
        self.root = TrieNode()
        self.word = ""
        self.mapping = {
            '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
        }

    def insert_word(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def generate_suggestions(self, node, current_word):
        suggestions = []
        if node.is_end_of_word:
            suggestions.append(current_word)
        for char, child in node.children.items():
            suggestions.extend(self.generate_suggestions(child, current_word + char))
        return suggestions

    def search_words(self, sequence, node, current, resp):
        if node.is_end_of_word:
            resp.append(current)
        if sequence:
            for c in self.mapping.get(sequence[0], []):
                if c in node.children:
                    self.search_words(sequence[1:], node.children[c], current + c, resp)
        else:
            for c, node in node.children.items():
                self.search_words(sequence, node, current + c, resp)


if __name__ == "__main__":
    t9_dict = T9Dictionary()
    t9_dict.insert_word("mane")
    t9_dict.insert_word("name")
    t9_dict.insert_word("oboe")
    t9_dict.insert_word("mang")
    t9_dict.insert_word("mabg")
    t9_dict.insert_word("hello")

    input_sequence = "6224"
    resp = []
    t9_dict.search_words(input_sequence, t9_dict.root, "", resp)
    print("Suggestions:", resp)

    print(t9_dict.generate_suggestions(t9_dict.root, "6224"))

import sys
class Node(object):

    def __init__(self, val):
        self.val = val
        self.children = {}
        self.word = None

# add results to this list to be printed out
result = []
morse = {}
context = []
encoded_words = []


# reads morse code alphabet
def read_morse():
    global morse
    while True:
        line = raw_input().strip()

        if line == '*':
            break
        elif line == '' or line.isspace():
            continue

        else:
            d = line.split()
            # Create a mapping between morse element as key to char as value
            # W .--  = {'.--':'W'}
            #print d
            if len(d) == 2:
                morse[d[1]] = d[0]


# Create Trie structure with context words. It helps in prefix matching
def construct_trie(root):
    global context

    for word in context:
        cur = root
        for c in word:
            if c not in cur.children:
                cur.children[c] = Node(c)
            cur = cur.children[c]
        cur.word = word
    return root


# reading the context of words
def read_context():
    global context
    while True:
        line = raw_input().strip()

        if line == '*':
            break
        elif line == '' or line.isspace():
            continue

        else:
            context.append(line.strip())
        # continue here


# parsing the words section
def parse_words():
    global encoded_words
    while True:
        line = raw_input().strip()

        if line == '*':
            break
        elif line == '' or line.isspace():
            continue
        else:
            l = line.split()

            for word in l:
                encoded_words.append(word)

    print encoded_words


class Decode(object):

    def __init__(self):
        self.perfect_match_count = 0
        self.matched_word = None
        self.imperfect_prefix = ''
        self.imperfect_match_length = 0
        self.imperfect_match_count = 0
        self.min_perfect_length = sys.maxint

    def initialize(self):
        self.perfect_match_count = 0
        self.matched_word = None
        self.imperfect_prefix = ''
        self.imperfect_match_length = 0
        self.imperfect_match_count = 0
        self.min_perfect_length = sys.maxint

    def find_word(self, root, prefix):
        cur = root
        for c in prefix:
            if c not in cur.children:
                possible_chars = cur.children
                return possible_chars
            cur = cur.children[c]

        return None


    # Return True or False along with matched character count
    def check_context(self, root, prefix):
        cur = root
        count = 0
        for c in prefix:
            if c not in cur.children:
                # find the closest children
                return (False, count)
            cur = cur.children[c]
            count = count + 1
        if cur.word and cur.word == prefix:
            return (True, count)
        else:
            return (False, count)

    # At each recrusion check find a valid break and pass it to recursive calls
    # When we are out of word check the trie and if its valid context add it result and break all together so that
    # we can move to next word
    def decode_word(self, root, word, word_so_for):

        if len(word) == 0:
            # 1) check if it is a perfect match
            ret, count = self.check_context(root, word_so_for)
            if ret:
                # perfect match
                #print "perfect match", word_so_for, count, self.min_perfect_length
                if self.min_perfect_length > count:
                    self.min_perfect_length = count
                    self.matched_word = word_so_for
                self.perfect_match_count += 1
                return True
            else:
                if not self.matched_word:
                    #print "imp", word_so_for
                    self.imperfect_match_count += 1
                    if count > self.imperfect_match_length:
                        # store the maximum matched imperfect word
                        self.imperfect_match_length = count
                        tmp = self.find_word(root, word_so_for[:count])
                        if tmp:
                            for pc in tmp:
                                word_so_for = word_so_for[:count] + pc
                                break
                        self.imperfect_prefix = word_so_for

                return False
        prefix = ''
        for i in range(len(word)):
            prefix = prefix + word[i]
            if str(prefix) not in morse.keys():
                continue
            else:
                #print "found", prefix, morse[prefix]
                cur_word = morse[prefix]
                ret = self.decode_word(root, word[i+1:], word_so_for+cur_word)

        return ret


    def decode(self, root):
        global result
        #print morse
        print encoded_words
        for word in encoded_words:
            #print "Decoding ", word
            prefix = ''
            self.initialize()
            self.imperfect_prefix = None
            self.matched_word = None
            self.decode_word(root, word, prefix)
            if self.matched_word:
                if self.perfect_match_count > 1:
                    self.matched_word = self.matched_word + '!'
                result.append(self.matched_word)
            else:
                if self.imperfect_match_count > 1:
                    if self.imperfect_prefix:
                        self.imperfect_prefix = self.imperfect_prefix + '?'
                result.append(self.imperfect_prefix)



# printing the result with matches
def print_result():

    for word in result:
        print(word)


if __name__ == '__main__':
    read_morse()
    read_context()
    parse_words()
    root = Node('root')

    root = construct_trie(root)
    obj = Decode()
    obj.decode(root)
    print_result()




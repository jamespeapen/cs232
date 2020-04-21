RAM_SIZE = 1024


class RAM:
    def __init__(self, size=RAM_SIZE):
        self._minAddr = 0
        self._maxAddr = RAM_SIZE - 1
        self._memory = []   # a list of values.  Could be #s or instructions.
        for i in range(size):
            self._memory.append(0)

    def __getitem__(self, addr):
        return self._memory[addr]

    def __setitem__(self, addr, val):
        self._memory[addr] = val

    def is_legal_addr(self, addr):
        return self._minAddr <= addr <= self._maxAddr

class MMU:
    '''Memory management unit'''
    def __init__(self, ram):
        self.ram = ram

    def get_ram_val(self, addr):
        '''get value from memory'''
        return self.ram.__getitem__(addr)

    def set_ram_val(self, addr, val):
        '''set a value in memory'''
        return self.ram.__setitem__(addr, val)



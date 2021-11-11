import gdb

class SecPrinter(object):
    "Muestra una secuencia"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        nodo_ptr = self.val['primero'].dereference()['sig']
        string_rep = "{";
        while (nodo_ptr != 0):
             string_rep = string_rep + str(nodo_ptr.dereference()['dato']) + ", "
             nodo_ptr = nodo_ptr.dereference()['sig']
        string_rep = string_rep + "\033[2D}"
        return string_rep

    def display_hint(self):
        return 'secuencia'

class par_intPrinter(object):
    "Muestra un par_int"

    def __init__(self,val):
        self.val = val

    def to_string(self):
        return "({}, {})".format(self.val['primero'], self.val['segundo'])
    
def my_pp_func(val):
    if str(val.type) == 'par_int': return par_intPrinter(val)
    elif str(val.type).startswith('Secuencia'): return SecPrinter(val)
    return None

gdb.pretty_printers.append(my_pp_func)

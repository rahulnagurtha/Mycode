#Thanks to https://github.com/hellman/libnum/blob/master/libnum/modular.py for open sourcing 
#the code which finds nCr mod K when n,r are very large and m is not prime
#
# I have used the code mentioned in the the above, and i used it as a sub-routine to solve the original problem



import operator


import math
import random


def len_in_bits(n):
    """
    Return number of bits in binary representation of @n.
    """
    try:
        return n.bit_length() # new in Python 2.7
    except AttributeError:
        if n == 0:
            return 0
        return len(bin(n)) - 2


def randint_bits(size):
    low = 1 << (size - 1)
    hi = (1 << size) - 1
    return random.randint(low, hi)


def ceil(x, y):
    return x / y + (x % y != 0)


def nroot(x, n):
    """
    Return truncated n'th root of x.
    """
    if n < 0:
        raise ValueError("can't extract negative root")

    if n == 0:
        raise ValueError("can't extract zero root")

    sign = 1
    if x < 0:
        sign = -1
        x = -x
        if n % 2 == 0:
            raise ValueError("can't extract even root of negative")

    high = 1
    while high ** n <= x:
        high <<= 1

    low = high >> 1
    while low < high:
        mid = (low + high) >> 1
        if low < mid and mid ** n < x:
            low = mid
        elif high > mid and mid ** n > x:
            high = mid
        else:
            return sign * mid
    return sign * (mid + 1)


def _gcd(a, b):
    """
    Return greatest common divisor using Euclid's Algorithm.
    """
    if a == 0: return b
    if b == 0: return a
    while b:
        a, b = b, a % b
    return abs(a)


def _lcm(a, b):
    """
    Return lowest common multiple.
    """
    if not a or not b:
        raise ZeroDivisionError("lcm arguments may not be zeros")
    return abs(a * b) // _gcd(a, b)


def gcd(*lst):
    """
    Return gcd of a variable number of arguments.
    """
    return abs(reduce(lambda a, b: _gcd(a, b), lst))


def lcm(*lst):
    """
    Return lcm of a variable number of arguments.
    """
    return reduce(lambda a, b: _lcm(a, b), lst)


def xgcd(a, b):
    """
    Extented Euclid GCD algorithm.
    Return (x, y, g) : a * x + b * y = gcd(a, b) = g.
    """
    if a == 0: return 0, 1, b
    if b == 0: return 1, 0, a

    px, ppx = 0, 1
    py, ppy = 1, 0

    while b:
        q = a // b
        a, b = b, a % b
        x = ppx - q * px
        y = ppy - q * py
        ppx, px = px, x
        ppy, py = py, y

    return ppx, ppy, a


def extract_prime_power(a, p):
    """
    Return s, t such that  a = p**s * t,  t % p = 0
    """
    s = 0
    if p > 2:
        while a and a % p == 0:
            s += 1
            a //= p
    elif p == 2:
        while a and a & 1 == 0:
            s += 1
            a >>= 1
    else:
        raise ValueError("Number %d is not a prime (is smaller than 2)" % p)
    return s, a


def solve_linear(a, b, c):
    """
    Solve a*x + b*y = c.
    Solution (x0 + b*n, y0 + a*n).
    Return None or (x0, y0).
    """
    #TODO: do
    return None






def grey_code(n):
    return n ^ (n >> 1)


def rev_grey_code(g):
    n = 0
    while g:
        n ^= g
        g >>= 1
    return n


def factorial(n):
    res = 1
    while n > 1:
        res *= n
        n -= 1
    return res


def factorial_get_prime_pow(n, p):
    """
    Return power of prime @p in @n!
    """
    count = 0
    ppow = p
    while ppow <= n:
        count += n // ppow
        ppow *= p
    return count


def nCk(n, k):
    """
    Combinations number
    """
    if n < 0: raise ValueError("Invalid value for n: %s" % n)
    if k < 0 or k > n: return 0
    if k in (0, n): return 1
    if k in (1, n-1): return n

    low_min = 1
    low_max = min(n, k)
    high_min = max(1, n - k + 1)
    high_max = n
    return reduce(operator.mul, range(high_min, high_max + 1), 1) / reduce(operator.mul, range(low_min, low_max + 1), 1)


def has_invmod(a, modulus):
    """
    Check if @a can be inversed under @modulus.
    Call this before calling invmod.
    """
    if modulus < 2:
        raise ValueError("modulus must be greater than 1")

    if a == 0 or gcd(a, modulus) != 1:
        return False
    else:
        return True


def invmod(a, n):
    """
    Return 1 / a (mod n).
    @a and @n must be co-primes.
    """
    if n < 2:
        raise ValueError("modulus must be greater than 1")

    x, y, g = xgcd(a, n)

    if g != 1:
        raise ValueError("no invmod for given @a and @n")
    else:
        return x % n


def solve_crt(remainders, modules):
    """
    Solve Chinese Remainder Theoreme.
    @modules and @remainders are lists.
    @modules must be pairwsise coprimes.
    """
    if len(modules) != len(remainders):
        raise TypeError("modules and remainders lists must have same len")

    if len(modules) == 0:
        raise ValueError("Empty lists are given")

    if len(modules) == 1:
        return remainders[0]

    x = 0
    N = reduce(operator.mul, modules)
    for i, module in enumerate(modules):
        if module == 1:
            continue

        Ni = N // module
        b = invmod(Ni, module)

        x += remainders[i] * Ni * b
    return x % N


def nCk_mod(n, k, factors):
    """
    Compute nCk modulo, factorization of modulus is needed
    """
    rems = []
    mods = []
    for p, e in factors.items():
        rems.append(nCk_mod_prime_power(n, k, p, e))
        mods.append(p ** e)
    return solve_crt(rems, mods)


def factorial_mod(n, factors):
    """
    Compute factorial modulo, factorization of modulus is needed
    """
    rems = []
    mods = []
    for p, e in factors.items():
        pe = p ** e
        if n >= pe or factorial_get_prime_pow(n, p) >= e:
            factmod = 0
        else:
            factmod = factorial(n) % pe
        rems.append(factmod)
        mods.append(pe)
    return solve_crt(rems, mods)


def nCk_mod_prime_power(n, k, p, e):
    """
    Compute nCk mod small prime power: p**e
    Algorithm by Andrew Granville:
        http://www.dms.umontreal.ca/~andrew/PDF/BinCoeff.pdf
    What can be optimized:
        - compute (n-k)*(n-k+1)*...*n / 1*2*...*k instead of n!, k!, r!
        - ...
    """

    def nCk_get_prime_pow(n, k, p):
        res = factorial_get_prime_pow(n, p)
        res -= factorial_get_prime_pow(k, p)
        res -= factorial_get_prime_pow(n - k, p)
        return res

    def nCk_get_non_prime_part(n, k, p, e):
        pe = p ** e
        r = n - k

        # print(n,k,p,e,pe,r)
         
        fact_pe = [1]
        acc = 1
        for x in xrange(1, pe):
            if x % p == 0:
                x = 1
            acc = (acc * x) % pe
            fact_pe.append(acc)

        # print(fact_pe)

        top = bottom =1
        is_negative = 0
        digits = 0

        while n != 0:
            if acc != 1:
                if digits >= e:
                    is_negative ^= n & 1
                    is_negative ^= r & 1
                    is_negative ^= k & 1


            top = (top * fact_pe[n % pe]) % pe
            bottom = (bottom * fact_pe[r % pe]) % pe
            bottom = (bottom * fact_pe[k % pe]) % pe


            n //= p
            r //= p
            k //= p

            digits += 1


        # print(top,bottom,is_negative,pe);

        res = (top * invmod(bottom, pe)) % pe

        # print(res,invmod(bottom, pe))

        if p != 2 or e < 3:
            if is_negative:
                res = pe - res
        return res

    prime_part_pow = nCk_get_prime_pow(n, k, p)
    if prime_part_pow >= e:
        return 0


    
    modpow = e - prime_part_pow

    r = nCk_get_non_prime_part(n, k, p, modpow) % (p ** modpow)
    
    return ((p ** prime_part_pow) * r) % (p ** e)

# print (nCk_mod_prime_power(5,2,2,3))


def factorise_into_prime_powers(n):
    ans = {}
    for x in xrange(2,1000000):
        p = x
        e = 0
        while (n % x) == 0:
            e += 1
            n = n/x
        if e > 0:
            ans[p] = e
    return ans


def get_ceil(a,b):
    if (a % b) == 0:
        return a/b
    else:
        return a/b + 1

num_cases = input()

for z in xrange(0,num_cases):
    n,k,m = map(int,raw_input().split())
    T = get_ceil(n, k)
    print T,nCk_mod(k*T - n + T - 1, T - 1, factorise_into_prime_powers(m))
    
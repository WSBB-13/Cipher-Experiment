//Download by http://www.NewXing.com
// very long integer - can be used like long
class vlong_value;
class flex_unit // Provides storage allocation and index checking
{
  unsigned * a; // array of units
  unsigned z; // units allocated
public:
  unsigned n; // used units (read-only)
  flex_unit();
  ~flex_unit();
  void clear(); // set n to zero
  unsigned get( unsigned i ) const;     // get ith unsigned
  void set( unsigned i, unsigned x );   // set ith unsigned
  void reserve( unsigned x );           // storage hint

  // Time critical routine
  void fast_mul( flex_unit &x, flex_unit &y, unsigned n );
};

class vlong_value : public flex_unit
{
  public:
  unsigned share; // share count, used by vlong to delay physical copying
  int is_zero() const;
  int test( unsigned i ) const;
  unsigned bits() const;
  int cf( vlong_value& x ) const;
  void shl();
  void shr();
  void shr( unsigned n );
  void add( vlong_value& x );
  void subtract( vlong_value& x );
  void init( unsigned x );
  void copy( vlong_value& x );
  operator unsigned(); // Unsafe conversion to unsigned
  vlong_value();
  void mul( vlong_value& x, vlong_value& y );
  void divide( vlong_value& x, vlong_value& y, vlong_value& rem );
};

class vlong
{
public:
  // Standard arithmetic operators
  friend vlong operator +( const vlong& x, const vlong& y );
  friend vlong operator -( const vlong& x, const vlong& y );
  friend vlong operator *( const vlong& x, const vlong& y );
  friend vlong operator /( const vlong& x, const vlong& y );
  friend vlong operator %( const vlong& x, const vlong& y );
  vlong& operator +=( const vlong& x );
  vlong& operator -=( const vlong& x );

  // Standard comparison operators
  friend inline int operator !=( const vlong& x, const vlong& y ){ return x.cf( y ) != 0; }
  friend inline int operator ==( const vlong& x, const vlong& y ){ return x.cf( y ) == 0; }
  friend inline int operator >=( const vlong& x, const vlong& y ){ return x.cf( y ) >= 0; }
  friend inline int operator <=( const vlong& x, const vlong& y ){ return x.cf( y ) <= 0; }
  friend inline int operator > ( const vlong& x, const vlong& y ){ return x.cf( y ) > 0; }
  friend inline int operator < ( const vlong& x, const vlong& y ){ return x.cf( y ) < 0; }

  // Construction and conversion operations
  vlong ( unsigned x=0 );
  vlong ( const vlong& x );
  ~vlong();
  operator unsigned ();
  vlong& operator =(const vlong& x);

public:
  class vlong_value * value;
private:
  int negative;
  int cf( const vlong x ) const;
  void docopy();
  friend class monty;
};

vlong modexp( const vlong & x, const vlong & e, const vlong & m );	// m must be odd
vlong gcd( const vlong &X, const vlong &Y );						// greatest common denominator
vlong modinv( const vlong &a, const vlong &m );						// modular inverse

//RSA
class public_key
{
  public:
  vlong m,e,md;
  vlong encrypt( const vlong& plain ); // Requires 0 <= plain < m
};

class private_key : public public_key
{
  public:
  vlong p,q;
  vlong decrypt( const vlong& cipher );

  void create( const char * r1, const char * r2,const char *r3);
  // r1 and r2 should be null terminated random strings
  // each of length around 35 characters (for a 500 bit modulus)
};
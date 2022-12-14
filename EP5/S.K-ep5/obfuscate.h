//https://github.com/SK-Shaiya
//if you get stuck :D just add me   [s.k#8903]

#include <cstddef>

namespace ay
{
	// Obfuscates a string at compile time
	template <std::size_t N, char KEY>
	class obfuscator
	{
	public:
		// Obfuscates the string 'data' on construction
		constexpr obfuscator(const char* data)
		{
			static_assert(KEY != '\0', "KEY must not be the null character.");

			// On construction each of the characters in the string is
			// obfuscated with an XOR cipher based on KEY
			for (std::size_t i = 0; i < N; i++)
			{
				m_data[i] = data[i] ^ KEY;
			}
		}

		constexpr const char* getData() const
		{
			return &m_data[0];
		}

		constexpr std::size_t getSize() const
		{
			return N;
		}

		constexpr char getKey() const
		{
			return KEY;
		}

	private:

		char m_data[N]{};
	};

	// Handles decryption and re-encryption of an encrypted string at runtime
	template <std::size_t N, char KEY>
	class obfuscated_data
	{
	public:
		obfuscated_data(const obfuscator<N, KEY>& obfuscator)
		{
			for (std::size_t i = 0; i < N; i++)
			{
				m_data[i] = obfuscator.getData()[i];
			}
		}

		~obfuscated_data()
		{
			// Zero m_data to remove it from memory
			for (std::size_t i = 0; i < N; i++)
			{
				m_data[i] = 0;
			}
		}

		
		operator char* ()
		{
			decrypt();
			return m_data;
		}

	
		void decrypt()
		{
			if (is_encrypted())
			{
				for (std::size_t i = 0; i < N; i++)
				{
					m_data[i] ^= KEY;
				}
			}
		}

		void encrypt()
		{
			if (!is_encrypted())
			{
				for (std::size_t i = 0; i < N; i++)
				{
					m_data[i] ^= KEY;
				}
			}
		}

		
		bool is_encrypted() const
		{
			return m_data[N - 1] != '\0';
		}

	private:

		
		char m_data[N];
	};

	
	template <std::size_t N, char KEY = '.'>
	constexpr auto make_obfuscator(const char(&data)[N])
	{
		return obfuscator<N, KEY>(data);
	}
}


#define AY_OBFUSCATE(data) AY_OBFUSCATE_KEY(data, '.')


#define AY_OBFUSCATE_KEY(data, key) \
	[]() -> ay::obfuscated_data<sizeof(data)/sizeof(data[0]), key>& { \
		constexpr auto n = sizeof(data)/sizeof(data[0]); \
		static_assert(data[n - 1] == '\0', "String must be null terminated"); \
		constexpr auto obfuscator = ay::make_obfuscator<n, key>(data); \
		static auto obfuscated_data = ay::obfuscated_data<n, key>(obfuscator); \
		return obfuscated_data; \
	}()



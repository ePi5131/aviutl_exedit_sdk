#pragma once

namespace ExEdit {
	namespace Variables {

		namespace __internal {
			template <typename T>
			struct variable_reference_type {
				using type = T*;
			};

			template <typename T>
			struct variable_reference_type<T[]> {
				using type = T**;
			};
		}

		template <typename T, bool isArray, unsigned int offset092, unsigned int offset093rc1>
		struct Variable {
			using type = T;
			static inline constexpr bool isArray = isArray;
			static inline constexpr unsigned int offset092 = offset092;
			static inline constexpr unsigned int offset093rc1 = offset093rc1;
			using reference_type = __internal::variable_reference_type<T>::type;
		};

		template <typename Variable>
		inline Variable::reference_type get092(const unsigned int exedit_base) {
			static_assert(Variable::offset092 != NULL, "offset address for ExEdit version0.92 is unknown");
			return reinterpret_cast<Variable::reference_type>(exedit_base + Variable::offset092);
		}

		template <typename Variable>
		inline Variable::reference_type get093rc1(const unsigned int exedit_base) {
			static_assert(Variable::offset093rc1 != NULL, "offset address for ExEdit version0.93rc1 is unknown");
			return reinterpret_cast<Variable::reference_type>(exedit_base + Variable::offset093rc1);
		}

	}
}

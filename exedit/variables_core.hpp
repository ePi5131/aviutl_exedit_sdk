#pragma once

namespace ExEdit {
	namespace Variables {

		template <typename T, bool IsArray = false>
		struct Variable {
			using type = T;
			static inline constexpr bool isArray = IsArray;
			using reference_type = T*;
		};

		template <typename T, bool IsArray>
		struct Variable<T[], IsArray> {
			using type = T[];
			static inline constexpr bool isArray = IsArray;
			using reference_type = T**;
		};

		template <typename Variable>
		constexpr Variable::reference_type get092(const unsigned int exedit_base) {
			return reinterpret_cast<Variable::reference_type>(exedit_base + Variable::offset092);
		}

		template <typename Variable>
		constexpr Variable::reference_type get093rc1(const unsigned int exedit_base) {
			return reinterpret_cast<Variable::reference_type>(exedit_base + Variable::offset093rc1);
		}

	}
}

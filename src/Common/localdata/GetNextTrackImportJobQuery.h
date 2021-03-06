#pragma once
#include <localdb/DBQuery.h>
#include "Entities.h"
namespace localdata {
	class GetNextTrackImportJobQuery : public LocalDB::ResultSetDBQuery<track_import_job> {
	private:
	protected:
		// Inherited via ResultSetDBQuery
		virtual std::string identifier() override;
		virtual std::string sql(int statementIndex) override;
		virtual track_import_job materialize(sqlite3 * db, sqlite3_stmt * statement) override;
	public:
		GetNextTrackImportJobQuery(const LocalDB::DBContext& context) : LocalDB::ResultSetDBQuery<track_import_job>(context) {}

	};

	concurrency::task<void> deleteImportedTrackAsync(LocalDB::DBContext& context, std::int64_t id, concurrency::cancellation_token cancelToken);
	concurrency::task<std::shared_ptr<imported_track>> getExistingImportedTrackIfExistsAsync(LocalDB::DBContext& context, std::int64_t id, concurrency::cancellation_token cancelToken);

	concurrency::task<void> transformTrackImportJobToImportedTrackAsync(LocalDB::DBContext& context, std::int64_t id, concurrency::cancellation_token cancelToken);
	concurrency::task<void> cancelTrackImportJobAsync(LocalDB::DBContext& context, std::int64_t id, concurrency::cancellation_token cancelToken);

	
}
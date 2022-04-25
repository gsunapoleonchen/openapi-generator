/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 6.0.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * StoreApi.h
 *
 * 
 */

#ifndef BOOST_BEAST_OPENAPI_CLIENT_StoreApi_
#define BOOST_BEAST_OPENAPI_CLIENT_StoreApi_

#include <memory>
#include <string>
#include <exception>

#include <boost/beast/core.hpp>

#include "api/HttpClient.h"

#include "Order.h"
#include <map>
#include <string>

namespace org {
namespace openapitools {
namespace client {
namespace api {

using namespace org::openapitools::client::model;

///
/// Exception to flag problems in the api's
///
class StoreApiException: public std::exception
{
public:
    StoreApiException(boost::beast::http::status statusCode, std::string what);

    boost::beast::http::status getStatus() const;
    const char* what() const noexcept override;

private:
    boost::beast::http::status m_status;
    std::string m_what;
};


class StoreApi {

public:
    StoreApi(
        std::shared_ptr<HttpClient>& client,
        const std::string& context = "/v2")
      : m_client(client),
        m_context(context)
    {}

    virtual ~StoreApi() = default;

    /// <summary>
    /// Delete purchase order by ID
    /// </summary>
    /// <remarks>
    /// For valid response try integer IDs with value &lt; 1000. Anything above 1000 or nonintegers will generate API errors
    /// </remarks>
    virtual void
    deleteOrder(
        const std::string& orderId);

    /// <summary>
    /// Find purchase order by ID
    /// </summary>
    /// <remarks>
    /// For valid response try integer IDs with value &lt;&#x3D; 5 or &gt; 10. Other values will generated exceptions
    /// </remarks>
    virtual std::shared_ptr<Order>
    getOrderById(
        const int64_t& orderId);
    /// <summary>
    /// Returns pet inventories by status
    /// </summary>
    /// <remarks>
    /// Returns a map of status codes to quantities
    /// </remarks>
    virtual std::map<std::string, int32_t>
    getInventory(
        );

    /// <summary>
    /// Place an order for a pet
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    virtual std::shared_ptr<Order>
    placeOrder(
        const std::shared_ptr<Order>& order);


protected:
    virtual std::string base64encode(const std::string& str);

    virtual void setPreferredMediaTypeHeader(
        std::map<std::string, std::string>& headers, const std::string& headerName, const std::vector<std::string>& contentTypes);

    virtual void handleStdException(
        const std::exception& e);
    virtual void handleUncaughtException();

    private:
    std::shared_ptr<HttpClient> m_client;
    std::string m_context;
};


}
}
}
}


#endif /* BOOST_BEAST_OPENAPI_CLIENT_StoreApi_ */
